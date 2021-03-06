CFLAGS=-Wall -O2 -pedantic -std=c99

all: replace swap scale newmatrix

replace: matrix.o replace.o

swap: matrix.o swap.o

scale: matrix.o scale.o

newmatrix: matrix.o newmatrix.o

clean:
	rm -f *.o replace swap scale newmatrix
