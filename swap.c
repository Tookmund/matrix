#include "matrix.h"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		fputs("swap [row] [row]\n", stderr);
		return 1;
	}
	matrix_t *m = loadmatrix();
	if (m == NULL) return 2;
	int r1 = atoi(argv[1])-1;
	int r2 = atoi(argv[2])-1;
	int *row1 = m->m[r1];
	int *row2 = m->m[r2];
	for (int i = 0; i < m->c; i++)
	{
		char t = row1[i];
		row1[i] = row2[i];
		row2[i] = t;
	}
	savematrix(m);
}

