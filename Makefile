CC = gcc
FLAGS = -Wall -g


.PHONY: all clean 

all: frequency

frequency.o:frequency.c 
	$(CC) $(FLAGS) -c frequency.c

frequency: frequency.o 
	$(CC) $(FLAGS) frequency.o -o frequency
	
clean:
	rm  *.o frequency