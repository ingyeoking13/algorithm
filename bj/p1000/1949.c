#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[10001], n, c[10001];
int dp[10001], dp2[10001];
typedef struct edge{ int u, v; struct edge* next; }edge;
edge *s[10001];

int max(int x, int y) { return x>y?x:y;}

void push(int u, int v){
	edge* tmp = (edge *) malloc(sizeof(edge));
	tmp->u = u;
	tmp->v = v;
	tmp->next =s[u];
	s[u] = tmp;
}

int dfs(edge* root, int chk){
	if (!root) 										return 0;
	if (chk 	 && dp[root->u]>=0) 	return dp[root->u];
	if ((!chk) && dp2[root->u]>=0) return dp2[root->u];

	if (chk){
		c[root->u]=1;
		dp[root->u]=a[root->u];

		edge* p= root;
		while(p){
			if ( ! c[p->v] ) dp[p->u]+=dfs( s[p->v], 0);
			p=p->next;
		}

		c[root->u]=0;
		return dp[root->u];
	}
	else {
		c[root->u]=1;
		dp2[root->u]=0;

		edge* p= root;
		while(p){
			if ( !c[p->v] ){
				dp2[p->u]+=max(dfs(s[p->v], 1), dfs(s[p->v], 0));
			}
			p=p->next;
		}

		c[root->u]=0;
		return dp2[root->u];
	}
}

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);

	for (int i=0; i<n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		push(u,v); push(v, u);
	}

	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));
	int ans=dfs(s[1], 1);
	ans=max(dfs(s[1], 0),ans);
	printf("%d\n", ans);
}
