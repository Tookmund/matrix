#include "matrix.h"

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		fputs("replace [row] [factor] [row to add] (/factor to divide)\n", stderr);
		return 1;
	}
	matrix_t *m = loadmatrix();
	if (m == NULL) return 2;
	char div = 0;
	int row = atoi(argv[1])-1;
	if (argv[2][0] == '/')
	{
		div = 1;
		argv[2]++;
	}
	int factor = atoi(argv[2]);
	int rowadd = atoi(argv[3])-1;
	for (int i = 0; i < m->c; i++)
	{
		int add = m->m[rowadd][i];
		if (div) add = add/factor;
		else add = add*factor;
		m->m[row][i] = m->m[row][i]+add;
	}
	savematrix(m);
	return 0;
}

