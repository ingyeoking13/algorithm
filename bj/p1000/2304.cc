#include <stdio.h>
#include <algorithm>

using namespace std;
int a[1001], b[1001], c[1001];
int main()
{
	int n; scanf("%d", &n);
	while(n--)
	{
		int l, h;
		scanf("%d %d", &l, &h);
		a[l]=h;
		b[l]=h;
	}

	for (int i=1; i<=1000; i++)
	{
		a[i] = max(a[i], a[i-1]);
	}
	for (int i=1000; i>0; i--)
	{
		b[i] = max(b[i], b[i+1]);
	}
	int ans=0;
	for (int i=1; i<= 1000; i++)
	{
		ans += min(a[i], b[i]);
		c[i] =min(a[i], b[i]);
	}
	printf("%d\n", ans);

}
