run: compile
	./bin/main < ./src/input.txt

compile:
	gcc src/main.c -o bin/main -lpthread

clean:
	rm -rf bin/*
	rm -rf doc/html
	rm -rf doc/latex

docs:
	doxygen config
