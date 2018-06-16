#include <stdio.h>


int a[]={1, 4, 9, 2, 8, 3, 6, 7, 5};
int p(int l, int h)
{

	int piv = a[l];
	int i = h+1;

	for (int j = h; j>l; j--)
	{

		if ( a[j] > piv )
		{
			i--;

			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	int tmp = a[i-1];
	a[i-1] = a[l];
	a[l] = tmp;
	return i-1;
}

void q(int l, int h)
{
	if ( l<h)
	{
		int piv = p(l, h);

		q(l, piv-1);
		q(piv+1, h);

		for (int i=0; i<9; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}

int main()
{
	q(0, 8);
}
