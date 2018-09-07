#include "matrix.h"

int main(void)
{
	puts("What is the size of the matrix?");
	int r, c;
	scanf("%d %d", &r, &c);
	matrix_t *m = creatematrix(r, c);
	for (int r = 0; r < m->r; r++)
	{
		for (int c = 0; c < m->c; c++)
		{
			printf("(%d,%d):", r+1, c+1);
			scanf("%d", &(m->m[r][c]));
		}
	}
	savematrix(m);
	return 0;
}

