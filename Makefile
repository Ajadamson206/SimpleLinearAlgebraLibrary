CC = gcc

LinearAlgebra: src/*
	mkdir -p build/
	cd build/ && \
	gcc ../src/*.c -c -fPIC -lm
	
	cd build/ && \
	gcc *.o -shared -o libLinAlg.so -lm

	cd build/ && \
	rm *.o

Tester: src/*
	CC *.c -o test -lm

Tester2:
	gcc tests/tester.c -o test -lm -L ./build -lLinAlg

Debug: src/*
	CC *.c -o test -fsanitize=undefined -lm -g --no-pie