Tester: *
	gcc *.c -o test -lm

Debug:
	gcc *.c -o test -fsanitize=undefined -lm