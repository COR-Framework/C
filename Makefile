cor_lib:
	gcc -shared cor/*.c -o libcor.dylib

test: cor_lib
	gcc test.c -o test -L. -lcor

run: cor_lib test
	./test

all: cor_lib
