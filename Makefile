CC=g++
FLAGS=${CFLAGS}
LFLAG=${LFLAGS}
# v8 monolithic lib release (from just-js)
RELEASE=0.1.14
# binary name
TARGET=spin
# name of runtime object on globalThis in JS
GLOBALOBJ="spin"
# we have to link dl as v8 requires it
LIB=-ldl
# directory to look for c++ modules
MODULE_DIR=module
# passed to module makefile so they can acces headers
SPIN_HOME=$(shell pwd)
# list of c++ library archive (.a) files to link into runtime
MODULES=module/load/load.a module/fs/fs.a
# list of JS modules to link into runtime
LIBS="lib/gen.js"
# list of arbitrary assets to link into runtime
ASSETS=
# when initializing a module, the path to the api defintion
MODULE_DEF=
# directory to look for native api bindings
BINDINGS_DIR=
# directory where scc binary is located
SCC_DIR=/home/andrew/go/bin
# flags for v8 compilation
V8_FLAGS="-DV8_DEPRECATION_WARNINGS=1 -DV8_IMMINENT_DEPRECATION_WARNINGS=1 -DV8_HAS_ATTRIBUTE_VISIBILITY=1"
#V8_FLAGS=

.PHONY: help clean

help:
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z0-9_\.-]+:.*?## / {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)

deps: ## download v8 monolithic library for linking
	mkdir -p deps
	curl -L -o v8lib-$(RELEASE).tar.gz https://raw.githubusercontent.com/just-js/libv8/$(RELEASE)/v8.tar.gz
	tar -zxvf v8lib-$(RELEASE).tar.gz
	rm -f v8lib-$(RELEASE).tar.gz

builtins.o: main.js builtins.S ## link the assets into an object file
	gcc -flto builtins.S -c -o builtins.o

builtins.S: ## generate the assembly file for linking assets into runtime
	./${TARGET} gen --link ${LIBS} ${ASSETS} > builtins.S

main.h: ## generate the main.h to initialize libs and modules
	./${TARGET} gen --header ${LIBS} ${MODULES} > main.h

main.o: main.h ## compile the main app
	$(CC) -flto -g -O3 -c ${FLAGS} ${V8_FLAGS} -DGLOBALOBJ='${GLOBALOBJ}' -DVERSION='"${RELEASE}"' -std=c++17 -DV8_COMPRESS_POINTERS -DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=0 -I. -I./deps/v8/include -march=native -mtune=native -Wpedantic -Wall -Wextra -Wno-unused-parameter main.cc

${TARGET}.o: ## compile the main library
	$(CC) -flto -g -O3 -c ${FLAGS} ${V8_FLAGS} -DGLOBALOBJ='${GLOBALOBJ}' -DVERSION='"${RELEASE}"' -std=c++17 -DV8_COMPRESS_POINTERS -DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=0 -I. -I./deps/v8/include -march=native -mtune=native -Wpedantic -Wall -Wextra -Wno-unused-parameter ${TARGET}.cc

${TARGET}: ${TARGET}.o main.o builtins.o ## link the runtime
	$(CC) -flto -g -O3 ${V8_FLAGS} -rdynamic -pthread -static-libstdc++ -static-libgcc -m64 -Wl,--start-group main.o deps/v8/libv8_monolith.a ${TARGET}.o builtins.o ${MODULES} -Wl,--end-group ${LFLAG} ${LIB} -o ${TARGET}
	objcopy --only-keep-debug ${TARGET} ${TARGET}.debug
	strip --strip-debug --strip-unneeded ${TARGET}
	objcopy --add-gnu-debuglink=${TARGET}.debug ${TARGET}

all:
	${MAKE} clean
	${MAKE} ${TARGET}

init: ${BINDINGS_DIR}/${MODULE} ## initialize a new module from an api definition
	mkdir -p ${MODULE_DIR}/${MODULE}

gen: ${TARGET} ## generate source and Makefile from definitions for a library
	./${TARGET} gen --make ${BINDINGS_DIR}/${MODULE}/${MODULE}.js > ${MODULE_DIR}/${MODULE}/Makefile
	./${TARGET} gen ${BINDINGS_DIR}/${MODULE}/${MODULE}.js > ${MODULE_DIR}/${MODULE}/${MODULE}.cc

scc: ## generate report on lines of code, number of files, code complexity
	${SCC_DIR}/scc --exclude-dir="deps,bench,test,.devcontainer,.git,.vscode,scratch,example,doc,docker,main.h,module/,test.js" --include-ext="cc,c,h,js,mk" --gen --wide --by-file ./ > scc.txt

library: ## build a spin shared library
	CFLAGS="$(FLAGS)" LFLAGS="${LFLAG}" SPIN_HOME="$(SPIN_HOME)" $(MAKE) -C ${MODULE_DIR}/${MODULE}/ library

clean: ## tidy up
	rm -f *.o
	rm -f ${TARGET}
	rm -f *.debug

cleanall: ## remove target and build deps
	rm -fr deps
	$(MAKE) clean
	rm -f ${TARGET}
	rm -f ${TARGET}.debug

.DEFAULT_GOAL := help