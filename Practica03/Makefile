programa1:
	bin/Prog1

programa2:
	bin/Prog2

programa3:
	bin/Prog3

comp:
	gcc -o bin/Prog1 src/Prog1.c
	gcc -o bin/Prog2 src/Prog2.c
	gcc -o bin/Prog3 src/Prog3.c

gendoc:
	doxygen config

clean:
	rm doc/* -rf
	rm bin/* -rf
	rm Makefile.* -rf
