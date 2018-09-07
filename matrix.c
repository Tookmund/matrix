#include "matrix.h"

#define MATRIXFILE "currentmatrix"

matrix_t *loadmatrix(void)
{
	FILE* f = fopen(MATRIXFILE, "r");
	if (f == NULL) return NULL;
	int r, c;
	fscanf(f, "%d %d", &r, &c);
	matrix_t *m = creatematrix(r, c);
	return m;
}

void matrixtofile(FILE *f, matrix_t *m)
{
	for (int r = 0; r < m->r; r++)
	{
		for (int c = 0; c < m->c; c++)
		{
			fprintf(f, "%d ", m->m[r][c]);
		}
		fprintf(f, "\n\n");
	}
}

int savematrix(matrix_t *m)
{
	FILE *f = fopen(MATRIXFILE, "w");
	if (f < 0) return -1;
	fprintf(f, "%d %d\n", m->r, m->c);
	matrixtofile(f, m);
	return 0;
}

void printmatrix(matrix_t *m)
{
	matrixtofile(stdout, m);
}

matrix_t *creatematrix(int r, int c)
{
	matrix_t *m = (matrix_t *)malloc(sizeof(matrix_t));
	if (m == NULL) return NULL;
	m->r = r;
	m->c = c;
	char **ar  = (char **)malloc(sizeof(char *) * r);
	if (ar == NULL) return NULL;
	ar[0] = (char *)malloc(sizeof(char) * c * r);
	if (ar[0] == NULL) return NULL;
	for (int i = 0; i < r; i++)
	{
		ar[i] = (*ar + c * i);
	}
	m->m = ar;
	return m;
}

void freematrix(matrix_t *m)
{
	free(&(m->m[0]));
	free(&(m->m));
	// Should free m but it appears to be a double-free
	//free(m);
}
