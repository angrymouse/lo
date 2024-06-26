## issues/tasks

- [x] **todo**:  fix clock_gettime/hrtime for macos
- [x] **todo**:  change namespace from spin to lo
- [x] **todo**:  get arm build working in github actions
- [x] **todo**:  fix assembly [issue](https://stackoverflow.com/questions/1034852/adding-leading-underscores-to-assembly-symbols-with-gcc-on-win32) - extra underscore on macos/windows
- [x] **todo**:  get windows build working
- [ ] **todo**:  add core module
- [ ] **todo**:  add lib/gen.js and other parts necessary to generate bindings
- [ ] **todo**:  add ffi
- [ ] **todo**:  get ffi working on arm64
- [ ] **issue**: clang does not work on raspberry pi linux
- [ ] **todo**:  a cleaner way to expose module resolution to JS
- [ ] **todo**:  use [this](https://github.com/marketplace/actions/run-on-architecture) to run tests on arm
- [ ] **todo**:  v8 inspector protocol support for debugging in vscode
- [ ] **todo**:  types and dx configurations for IDEs - autogenerate as much as possible
- [ ] **todo**:  fix hrtime() on windows
- [ ] **todo**:  get binary includes working for windows
- [ ] **todo**:  add method in github actions to test arm64 builds in a vm/emulator
- [ ] **todo**:  ffi support for arm64 on macos and linux and for x64 on windows
- [ ] **todo**:  ffi support for floats, structs and callbacks
- [ ] **todo**:  snapshot support - expose api to JS if possible
- [ ] **bug**:   static link on linux/arm64 is broken: ```mold -run make LARGS="-static" ARCH=arm64 C="ccache gcc" CC="ccache g++" clean lo```
- [ ] **todo**:  support android, libcosmo and risc-v. all 64 bit only.
- [ ] **todo**:  run release workflow on release created event and add changelog automatically
- [ ] **todo**:  add v8 LICENSE file from build
- [ ] **todo**:  path translation in core for lib/gen.js and modules
- [ ] **todo**:  tests for all build options
- [ ] **todo**:  script for bumping version number
- [ ] **todo**:  consolidate method for generating builtins on win/unix currently takes 11.4 ms for win and 8.1ms for unix for link the windows method is crazy slow the more files you have to do
- [ ] **todo**:  set something up to record build sizes and metrics/benches so we can track over time
- [ ] **todo**:  commands - install, uninstall, update
- [ ] **todo**:  change to using lib for bindings and libs
- [ ] **todo**:  overriding and hooking of module resolution
- [ ] **todo**:  language server
- [ ] **todo**:  snake case
- [ ] **todo**:  can we unload bindings and modules? have a look into this
- [ ] **bug**:   if i embed the binding definition and change it then the lib won't rebuild as it uses embedded one
- [ ] **todo**:  change binding defs so we can have multiple entries with same name but with different options for arch and platform
- [ ] **todo**:  pass a flag to gen to tell it what os/arch we want to generate for
- [ ] **bug**:   when rebuilding after changing bindings defs, they don't get re-generated as the ones on disk are not re-loaded.
- [ ] **todo**:  clean up lib/gen.js. it's a real mess
- [ ] **todo**:  have an embed cache separate from lib and require caches so we always load them from disk. hmmm... we need a nice way to handle this
- [ ] **todo**:  module resolution is really broken
- [ ] **todo**:  setTimeout, clearTimeout, setInterval, clearInterval
- [ ] **todo**:  performance.now()
- [ ] **todo**:  in assert, strip the assert line from the stack trace on the error
- [ ] **question**: should we have something like __dirname on each module?
- [ ] **todo**:  make lib/proc exec() async and used pidfd_open to monitor process on event loop
- [ ] **todo**:  freeze core apis/intrinsics
- [ ] **question**: how do we handle compiling dependencies of bindings cross platform if we don't depend on make?
                    we could just write the build script as js?
- [ ] **question**: how do we align structs in memory?
- [ ] **todo**:  ability to chain cli args together
- [ ] **todo**:  repl - doesn't really need async for now - ```lo repl```
- [ ] **todo**:  rename lo.library and lo.libraries to lo.binding and lo.bindings
- [ ] **todo**:  proc.js - mem() doesn't work on macos (no proc fs)
- [ ] **bug**:   if i run ```lo main.js``` it goes into a loop as it tries to recursively load the builtin main.js
- [ ] **bug**: for static libraries, we need to compile without -fPIC: https://stackoverflow.com/questions/28187163/how-do-you-link-a-static-library-to-a-shared-library
- [ ] **todo**: change inflate builder to download the depencies rather than having them embedded in the runtime
- [ ] **todo**: we need an SSE4 alternative (NEON?) for arm64 for picohttpparser
- [ ] **todo**: handle bindings methods that are optional based on defines
- [ ] **todo**: think about how we handle fork. can we handle it?
- [ ] **bug**: we open file twice with the LO_HOME core loader - refactor this so it works better
- [ ] **todo**: implement a way of building with a subset of bindings that work cross-platform for builder config - e.g. linux/mac
                maybe just put ifdef macros in the bindings cpp source for different platforms? it's auto-generate so that's ok
- [ ] **todo**: add ability to download and build dependencies and build our own version of a binding (e.g. libssl) or dynamically link to system library - switch on command line?
- [ ] **todo**: fix build.js for libssl so it works for compiling openssl from scratch
- [ ] **todo**: add a safe_wrap method to main.js so we can wrap pointers with a check for maxsafeinteger
- [ ] **todo**: when i do ```lo build binding <new_binding>``` generate binding definition with all cases covered and lots of comments, or not...
- [ ] **todo**: figure out a nice way to write modules that work on different platforms. can we pre-process the js in some way to only include code for that platform in the binary?
- [ ] **bug**:  when i do ```lo build``` after downloading runtime it fails because em_inflate source files are not in the binary and the build script is not available in lib/inflate. how do we resolve this?
- [ ] **question**: how do we model constants like RTLD_DEFAULT which seem to be pointers to things?
- [ ] **bug**:  on macos, when i do a ```lo build``` it generates same main.h for main.h main_win.h and main_mac.h
- [ ] **todo**: we need a way to ignore auto-generated files for git, but also to be able to re-generate them to check in when we need to.
- [ ] **todo**: figure out a way to create builtins for v8 and have them automatically baked in, e.g.
    https://github.com/denoland/v8/commit/8feae8c6166c2867554fb3f99fdd2b59a4a83c37
    https://github.com/denoland/v8/commit/2ca3e486b84398f163775450e7d0cc3f4868c981
    https://github.com/denoland/v8/commit/ae31efc15ffc948d1616d5e393a8f62fff1bfce8
- [ ] **todo**: use CC and CXX instead of C and CC
- [ ] **todo**: when building, do some pre-processing like stripping comments, minification and compression
- [ ] **bug**: bug in linux event loop where event loop drops out after all tcp server connections go away. but we should still have the server fd and the timer on the loop
- [ ] **todo**: allow setting arch: ```['arm64', 'x64']``` on bindings definitions so we can exclude for certain arches (e.g. boringssl)
- [ ] **bug**: cannot compile boringssl with -fPIC
- [ ] **bug**: SIGWNCH kills the app
- [ ] **todo**: change console.log and console.error in threads so they don't write to stdout and stderr
- [ ] **todo**: try/catch in loop callback and call on_error if we get an error
- [ ] **todo**: make build.js build method async
- [ ] **todo**: add a method for reading a bindary builtin into a buffer, or even just reading it as a memory stream. - wrapmemory? mmap? memfd_create?

## features

- [ ] **commands**: ability to host command scripts so i can run ```lo cmd blah``` and it will run blah.js from cmd direction in current dir or $HOME/.lo/cmd
- [ ] **fetch**: a robust and fast fetch implementation
- [ ] **serve**: a robust and fast http serve implementation with Request and Response
- [ ] **ffi**: a robust and fast ffi implementation
- [ ] **spawn**: a robust and fast process spawning and control implementation
- [ ] **resources**: a solution for tracking handles, pointers and file descriptors
- [ ] **hot loading**: look at ability to easily swap code out on the fly
- [ ] **v8 api**: create a simple c api around v8 (like rusty_v8) so we can use it in bindings and compile/link bindings with tcc (maybe - i think so - the bindings libraries can be plain c)
- [ ] **tracing**: a system for hooking into traces events for logging, metrics etc.
- [ ] **todo**: use new format for bindings to allow same method for multiple platforms
                get platform filtering working with bindings generation
- [ ] **bug** : mbedtls fails to compile on raspberry pi
- [ ] **todo**: redirection of stdin/out/err for child processes
- [ ] **todo**: cacheing for binding dependencies builder
- [ ] **todo**: fix the CC env var issue. this should be C compiler, not C++

## modules

- [ ] **Worker**: a robust and fast Web Worker implementation
- [ ] **WebSocket**: a robust and fast websocket implementation - client and server
- [ ] **sqlite**: a robust and fast sqlite implementation
- [ ] **thread**: thread library


