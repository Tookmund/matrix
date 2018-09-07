#include "matrix.h"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		fputs("scale [row] [factor]", stderr);
		return 1;
	}
	matrix_t *m = loadmatrix();
	if (m == NULL) return 2;
	int row = atoi(argv[1])-1;
	int factor = atoi(argv[2]);
	for (int i = 0; i < m->c; i++) m->m[row][i] = m->m[row][i]*factor;
	savematrix(m);
	return 0;
}

