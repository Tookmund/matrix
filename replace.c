#include "matrix.h"

int main(int argc, char **argv)
{
	matrix_t *m = loadmatrix();
	if (argc < 4)
	{
		puts("replace [row] [factor] [row to add]");
		return 1;
	}
	int row = atoi(argv[1])-1;
	int factor = atoi(argv[2]);
	int rowadd = atoi(argv[3])-1;
	for (int i = 0; i < m->c; i++)
	{
		m->m[row][i] = m->m[row][i]+(factor*m->m[rowadd][i]);
	}
	savematrix(m);
	return 0;
}

