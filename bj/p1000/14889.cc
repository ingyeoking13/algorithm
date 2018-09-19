#include <stdio.h>
int n, a[20][20], mn= 0x3f3f3f3f;
int b[20];

void dfs(int now, int cnt)
{
	if (cnt > n/2) return;
	if (now==n)
	{

		int ateam=0, bteam=0;
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				if (i== j) continue;
				if (b[i] && b[j]) ateam += a[i][j];
				else if ( b[i]==0 && b[j] ==0) bteam +=a[i][j];
			}
		}

		int ans = ateam-bteam;
		ans = ans>0?ans:-ans;

		if ( mn > ans) mn=ans;
		return;
	}

	b[now] = 1;
	dfs(now+1, cnt+1);
	b[now] = 0;
	dfs(now+1, cnt);
}
int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	dfs(0, 0);
	printf("%d\n", mn);
}
