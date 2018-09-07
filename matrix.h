#ifndef LOAD_MATRIX_H
#define LOAD_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
	char **m;
	int r;
	int c;
} matrix_t;

matrix_t *loadmatrix(void);

int savematrix(matrix_t *matrix);

void printmatrix(matrix_t *matrix);

matrix_t *creatematrix(int r, int c);

void freematrix(matrix_t *m);
#endif
