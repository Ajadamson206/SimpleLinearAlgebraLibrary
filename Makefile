CC = gcc

LinearAlgebra: src/*
	mkdir -p build/
	cd build/ && \
	gcc ../src/*.c -c -fPIC
	
	cd build/ && \
	gcc *.o -shared -o libLinAlg.so

	cd build/ && \
	rm *.o

Tester: src/*
	CC *.c -o test -lm

Debug: src/*
	CC *.c -o test -fsanitize=undefined -lm -g --no-pie