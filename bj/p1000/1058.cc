#include <bits/stdc++.h>

using namespace std;
char s[50][51]; int v[50], ans;
typedef struct {int n, d; }node;
queue<node> q;

int main(){
	int n; scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%s", s[i]);

	for (int i=0; i<n; i++){
		memset(v, 0, sizeof(v));
		q.push({i, 0}); v[i]=1;

		while(!q.empty()){
			node now = q.front(); q.pop();
			if (now.d == 2) continue;
			for (int j=0; j<n; j++){
				if ( s[now.n][j]=='Y' && !v[j] ){
					v[j]=1;
					q.push({j, now.d+1});
				}
			}
		}

		int tmp=-1;
		for (int i=0; i<n; i++) if(v[i]) tmp++;
		if (tmp>ans) ans=tmp;
	}

	printf("%d\n", ans);
}
