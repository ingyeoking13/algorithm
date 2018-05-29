#include <stdio.h>

using namespace std;
long long d[65][10];
int main()
{
	for (int i=0; i<=9; i++) d[1][i]=1;
	for (int i=2; i<=64; i++)
	{
		for (int j=0; j<=9; j++)
		{
			for (int k=0; k<=j; k++)
			{
				d[i][j] += d[i-1][k];
			}
		}
	}

	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		long long ans = 0;
		for (int i=0; i<=9; i++) ans += d[n][i];
		printf("%lld\n" ,ans);
	}
}
