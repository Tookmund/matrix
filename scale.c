#include "matrix.h"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		fputs("scale [row] [factor] (/factor to divide)\n", stderr);
		return 1;
	}
	matrix_t *m = loadmatrix();
	if (m == NULL) return 2;
	int row = atoi(argv[1])-1;
	char div = 0;
	if (argv[2][0] == '/')
	{
		div = 1;
		argv[2]++;
	}
	int factor = atoi(argv[2]);
	for (int i = 0; i < m->c; i++)
	{
		int add = m->m[row][i];
		if (div) add = add/factor;
		else add = add*factor;
		m->m[row][i] = add;
	}
	savematrix(m);
	return 0;
}

