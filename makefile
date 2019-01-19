ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

maze-generator: build/Main.o
	g++ $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system
build/Main.o: src/main.cpp build
	g++ $? -c -o $@
build:
	mkdir build
run: maze-generator
	./$<
clean:
	-rm -rf build/
	-rm maze-generator