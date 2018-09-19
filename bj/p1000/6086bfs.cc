#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

queue<int> q;
int capa[52][52], p[52], v[52];
int pre(char c)
{
	if ( 'A'<= c && c<= 'Z') return c-'A';
	return c-'a'+26;
}

int main()
{

	int n; scanf("%d", &n);
	while(n--)
	{
		char a[3], b[3]; int w; 
		scanf("%s %s %d", a, b, &w);
		a[0] = pre(a[0]), b[0] = pre(b[0]);
		capa[a[0]][b[0]] += w;
		capa[b[0]][a[0]] += w;
	}

	int ans=0;
	while(1)
	{
		memset(p, -1, sizeof(p));
		memset(v, 0, sizeof(v));
		q.push(0);
		v[0]=1;
		while(!q.empty())
		{
			int now = q.front(); q.pop();
			for (int i=0; i<52; i++)
			{
				if (capa[now][i] >0) 
				{
					if ( v[i] == 0) 
					{
						v[i] = 1;
						p[i] = now;
						q.push(i);
					}
				}
			}
		}

		int now = 25;
		if ( p[now] == -1 ) break;

		int mn = capa[p[now]][now];
		while(p[now] !=-1)
		{
			mn = min(capa[p[now]][now], mn);
			now= p[now];
		}
		now = 25;
		while(p[now] != -1)
		{
			capa[p[now]][now] -= mn;
			capa[now][p[now]] += mn;
			now= p[now];
		}
		ans += mn;
	}
	printf("%d\n", ans);
}
