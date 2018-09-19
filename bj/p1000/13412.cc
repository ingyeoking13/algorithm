#include <stdio.h>

int gcd(int a, int b)
{
	if (b==0) return a;
	return gcd(b, a%b);
}

int main()
{
	int n; scanf("%d", &n);

	while(n--)
	{

		int ans=0;
		int num; scanf("%d", &num);

		for (int i=1; i*i<=num; i++)
		{
			if ( num%i ==  0)
			{
				int g = gcd(i, num/i);
				if(g==1) ans++;

			}

		}
		printf("%d\n", ans);


	}
}
