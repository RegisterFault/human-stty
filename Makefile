all: main.c
	gcc -O2 main.c -o human-stty
debug: main.c
	gcc -ggdb main.c -o human-stty
