#include <stdio.h>

int a[5];
int main()
{
	int n; scanf("%d", &n);
	int mx=-1, id=-1;

	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<5; j++) scanf("%d", &a[j]);

		for (int j=0; j<5; j++)
		{
			for (int k=j+1; k<5; k++)
			{
				for (int l=k+1; l<5; l++)
				{
					int my = (a[j] + a[k] +a[l])%10;
					if ( mx <=my) mx = my, id = i;
				}
			}
		}
	}
	printf("%d\n", id);
}
