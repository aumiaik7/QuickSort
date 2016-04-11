CC=g++
CFLAGS=-c 


all: qsort

qsort: qsort.o 
	$(CC) qsort.o -o qsort

qsort.o: qsort.cc
	$(CC) $(CFLAGS) qsort.cc -g


clean:
	rm -rf *.o *~ qsort
	 


