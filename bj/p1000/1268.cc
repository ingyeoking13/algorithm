#include <stdio.h>

int a[1001][6];
int chk[1001][1001];
int d[1001][6];
int main()
{
	int n;  scanf("%d", &n);
	for (int i=0; i<n; i++)
		for (int j=1; j<=5; j++) scanf("%d", &a[i][j]);

	for (int i=0; i<n; i++)
	{
		for (int j=1; j<6; j++)
		{
			d[i][j] = d[i][j-1];

			for (int k=0; k<n; k++)
			{
				if( a[i][j] == a[k][j] )
				{
					if (!chk[i][k])
					{
						d[i][j]++;
						chk[i][k]=1;
					}
				}
			}
		}
	}

	int ans=-1, mx=-1;
	for (int i=0; i<n; i++)
	{
		if ( mx < d[i][5] ) mx=d[i][5], ans=i+1;
	}
	printf("%d\n", ans);

}
