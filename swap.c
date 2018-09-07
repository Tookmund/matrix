#include "matrix.h"

int main(int argc, char **argv)
{
	matrix_t *m = loadmatrix();
	if (argc < 3)
	{
		puts("swap [row] [row]");
		return 1;
	}
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
	freematrix(m);
}

