#include <stdio.h>

int g[1001][1001];
int c[1001]={1};
int n, m, v;
int q[1001], c2[1001]={1}, tail, head;

void dfs(int num){
	printf("%d ", num);
	c[num]=1;
	for (int i=1; i<=n;i++){
		if (g[num][i] && c[i]==0) {
			dfs(i);
		}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &v);

	int a, b;
	while(m--){
		scanf("%d %d", &a, &b);
		g[a][b]=1;
		g[b][a]=1;
	}

	dfs(v);
	printf("\n");

	c2[v]=1; q[tail++]=v;

	while(head<tail){
		int now= q[head++];
		printf("%d ", now);
		for (int i=1; i<=n; i++){
			if (g[now][i] && c2[i]==0) {
				c2[i]=1;
				q[tail++]=i;
			}
		}
	}
	printf("\n");
}
