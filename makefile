CC=gcc 
CFLAGS=-Wall -std=c99

poetry: poetry.o main.o
	$(CC) $(CFLAGS) poetry.o main.o -o poetry
poetry.o: poetry.c header.h
	$(CC) $(CFLAGS) -c poetry.c
main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c
clean:
	rm *.o poetry