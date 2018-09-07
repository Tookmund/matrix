#include "matrix.h"

int main(int argc, char **argv)
{
	matrix_t *m = loadmatrix();
	if (argc < 3)
	{
		puts("scale [row] [factor]");
		return 1;
	}
	int row = atoi(argv[1])-1;
	int factor = atoi(argv[2]);
	for (int i = 0; i < m->c; i++) m->m[row][i] = m->m[row][i]*factor;
	savematrix(m);
	return 0;
}

