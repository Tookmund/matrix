#include "matrix.h"

int main(void)
{
	puts("What is the size of the matrix?");
	int r, c;
	scanf("%d %d", &r, &c);
	matrix_t *m = creatematrix(r, c);
	printmatrix(m);
	freematrix(m);
	return 0;
}

