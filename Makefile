find_subimage: main.o
	gcc -g $(shell pkg-config --libs opencv) -o find_subimage main.o

main.o: main.c
	gcc -g $(shell pkg-config --cflags opencv) -c -o main.o main.c

clean:
	rm -f find_subimage *.o
