#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
char v[52];
int capa[52][52];

int pre(char c) {
	if ( 'a'<= c && c<= 'z' ) return 26+c-'a';
	else return c-'A';
}

int dfs(int now, int flow)
{
	if (v[now]) return 0;
	if (now == 25) return flow;
	v[now]=1;

	for (int i=0; i<52; i++)
	{
		if (capa[now][i]>0)
		{
			int f;
			if(f=dfs(i, min(capa[now][i], flow)) )
			{
				capa[now][i] -=f;
				capa[i][now] +=f;
				return f;
			}
		}
	}
	return 0;
}

int main()
{

	int n; scanf("%d", &n); 
	while(n--)
	{
		char u[3], v[3];
		int w;
		scanf("%s %s %d", u, v, &w);
		u[0] = pre(u[0]), v[0] = pre(v[0]);
		capa[u[0]][v[0]]+=w;
	}

	int ans=0;
	while(1)
	{
		memset(v, 0, sizeof(v));
		int f = dfs(0, 1e9);
		if(f == 0) break;
		ans += f;
	}

	printf("%d\n", ans);

}
