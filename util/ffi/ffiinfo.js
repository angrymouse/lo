import { Library } from 'lib/ffi.js'

const u8 = spin.ptr(spin.fs.readFile('ffiinfo.c'))
const src = spin.utf8Decode(u8.ptr, u8.byteLength)
const lib = new Library()
lib.open().compile(src, './ffiinfo.o')
console.log(Object.getOwnPropertyNames(lib))