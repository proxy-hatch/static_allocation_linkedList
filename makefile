CC=gcc
CFLAGS=-w -std=c99
PROG=run
OBJS= LIST.o main.o

run: $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

LIST.o: LIST.c LIST.h
	$(CC) $(CFLAGS) -c LIST.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm *.o