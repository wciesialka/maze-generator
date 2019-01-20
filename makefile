ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

maze-generator: build/Main.o build/Cell.o build/Grid.o
	g++ $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system
build/Main.o: src/Main.cpp src/Grid.cpp src/Cell.cpp build
	g++ -c $< -o $@
build/Grid.o: src/Grid.cpp src/Grid.h src/Cell.cpp build
	g++ -c $< -o $@
build/Cell.o: src/Cell.cpp src/Cell.h build
	g++ -c $< -o $@
build:
	mkdir build
run: maze-generator
	./$<
clean:
	-rm -rf build/
	-rm maze-generator