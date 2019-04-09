run: compile
	./bin/main 15

compile:
	gcc src/main.c -o bin/main

clean:
	rm -rf bin/*
	rm -rf doc/html
	rm -rf doc/latex

docs:
	doxygen config
