//import { Library } from 'lib/ffi.js'
//import * as sqlite3 from 'bindings/sqlite/sqlite.js'

//const sqlite = (new Library()).open('./libsqlite3.so').bind(sqlite3.api)

const { sqlite } = spin.load('sqlite')

const {
  step, column_int, column_double, reset, finalize,
  open2, exec, close2, prepare2, column_count,
  column_type, column_bytes
} = sqlite

const { assert, utf8Decode, utf8Length } = spin

const u32 = new Uint32Array(2)
const errmsg = spin.wrap(u32, sqlite.errmsg, 1)
const column_name = spin.wrap(u32, sqlite.column_name, 2)
const column_text = spin.wrap(u32, sqlite.column_text, 2)

const OK = 0
const ROW = 100
const DONE = 101
const OPEN_CREATE = 0x00000004
const OPEN_READWRITE = 0x00000002
const OPEN_NOMUTEX = 0x00008000

class Database {
  open (path, flags = OPEN_CREATE | OPEN_READWRITE | OPEN_NOMUTEX) {
    assert(open2(path, u32, flags, 0) === OK)
    this.db = u32[0] + ((2 ** 32) * u32[1])
    return this
  }

  error () {
    return utf8Decode(errmsg(this.db), -1)
  }

  exec (sql) {
    assert(exec(this.db, sql, 0, 0, u32) === OK)
    return this
  }

  prepare (sql) {
    return (new Statement(this.db)).prepare(sql)
  }

  close () {
    assert(close2(this.db) === OK)
  }
}

class Statement {
  types = []
  names = []
  columns = 0
  maxRows = 65536
  count = 0

  constructor (db) {
    this.db = db
  }

  prepare (sql) {
    assert(prepare2(this.db, sql, utf8Length(sql), u32, 0) === OK)
    const stmt = this.stmt = u32[0] + ((2 ** 32) * u32[1])
    if (this.columns == 0) {
      if (step(stmt) === ROW) {
        this.columns = column_count(stmt)
        for (let i = 0; i < this.columns; i++) {
          this.names.push(utf8Decode(column_name(stmt, i), -1))
          this.types.push(column_type(stmt, i))
        }
      }
      reset(stmt)
    }
    return this
  }

  step () {
    return step(this.stmt)
  }

  columnInt (index = 0) {
    return column_int(this.stmt, index)
  }

  columnBytes (index = 0) {
    return column_bytes(this.stmt, index)
  }

  columnDouble (index = 0) {
    return column_double(this.stmt, index)
  }

  columnText (index = 0) {
    const ptr = column_text(this.stmt, index)
    if (!ptr) return ''
    return utf8Decode(ptr, -1)
  }

  reset () {
    reset(this.stmt)
  }

  finalize () {
    finalize(this.stmt)
  }

  get () {
    const { types, names, columns, stmt } = this
    if(step(stmt) === ROW) {
      const row = {}
      for (let i = 0; i < columns; i++) {
        if (types[i] === 1) {
          row[names[i]] = column_int(stmt, i)
        } else if (types[i] === 2) {
          row[names[i]] = column_double(stmt, i)
        } else if (types[i] === 3) {
          row[names[i]] = this.columnText(i)
        }
      }
      this.reset()
      return row
    }
  }

  all () {
    const { types, names, columns, stmt } = this
    const rows = []
    let rc = step(stmt)
    let count = 0
    while (rc === ROW) {
      const row = {}
      for (let i = 0; i < columns; i++) {
        // todo: these could be indexes into a function table
        if (types[i] === 1) {
          row[names[i]] = column_int(stmt, i)
        } else if (types[i] === 2) {
          row[names[i]] = column_double(stmt, i)
        } else if (types[i] === 3) {
          row[names[i]] = this.columnText(i)
        }
      }
      rows.push(row)
      count++
      rc = step(stmt)
    }
    assert(rc === OK || rc === DONE)
    this.count = count
    this.reset()
    return rows
  }

  compile (className = 'Row', fixed = false) {
    const { types, names } = this
    const source = []
    let name
    let i = 0
    source.push(`class ${className} {`)
    for (const type of types) {
      name = names[i]
      if (type === 1) {
        source.push(`  ${name} = 0`)
      } else if (type === 2) {
        source.push(`  ${name} = 0.0`)
      } else if (type === 3) {
        source.push(`  ${name} = ''`)
      }
      i++
    }
    source.push('}')
    source.push(`return ${className}`)
    this.Row = (new Function(source.join('\n')))()
    this.rows = new Array(this.maxRows).fill(0).map(v => (new this.Row()))
    source.length = 0
    source.push(`
const { types, names, cols, rows, stmt } = this
let rc = step(stmt)
let i = 0
while (rc === ROW) {
`)
    if (fixed) {
      source.push('  const row = rows[i]')
    } else {
      source.push(`  const row = rows[i] = new ${className}()`)
    }
    i = 0
    for (const type of types) {
      if (type === 1) {
        source.push(`  row['${names[i]}'] = column_int(stmt, ${i})`)
      } else if (types[i] === 2) {
        source.push(`  row['${names[i]}'] = column_double(stmt, ${i})`)
      } else if (types[i] === 3) {
        source.push(`  row['${names[i]}'] = this.columnText(${i})`)
      }
      i++
    }
    source.push(`
  rc = step(stmt)
  i++
}
this.count = i
assert(rc === OK || rc === DONE)
this.reset()
return rows.slice(0, i)
`)
    this.all = (new Function('step', 'ROW', 'column_int', 
      'column_double', 'u32', 'assert', 
      'OK', 'DONE', className, 
      `return function () {
        ${source.join('\n').split('\n').filter(l => l).join('\n')}
      }`))(
        step, ROW, column_int, column_double, u32, 
        assert, OK, DONE, this.Row
      )
    source.length = 0
    source.push(`const { types, names, rows, stmt } = this`)
    if (fixed) {
      source.push('const row = rows[0]')
    } else {
      source.push(`const row = rows[0] = new ${className}()`)
    }
    source.push(`if (step(stmt) === ROW) {`)
    i = 0
    for (const type of types) {
      if (type === 1) {
        source.push(`  row['${names[i]}'] = column_int(stmt, ${i})`)
      } else if (types[i] === 2) {
        source.push(`  row['${names[i]}'] = column_double(stmt, ${i})`)
      } else if (types[i] === 3) {
        source.push(`  row['${names[i]}'] = this.columnText(${i})`)
      }
      i++
    }
    source.push(`}
this.reset()
return row
`)
    this.get = (new Function('step', 'ROW', 'column_int', 
      'column_double', 'u32', 'assert', 
      'OK', 'DONE', className, 
      `return function () {
        ${source.join('\n').split('\n').filter(l => l).join('\n')}
      }`))(
        step, ROW, column_int, column_double, u32, 
        assert, OK, DONE, this.Row
      )

    return this
  }

}

export { Database, Statement }

// todo - check for errors on step and column functions