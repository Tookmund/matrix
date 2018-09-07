#include "matrix.h"

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		fputs("replace [row] [factor] [row to add]", stderr);
		return 1;
	}
	matrix_t *m = loadmatrix();
	if (m == NULL) return 2;
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

