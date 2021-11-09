all: AAtree.c main.c
		gcc -Wall -o AAtree $^
clean:
		rm AAtree