#include <stdio.h>
#include <queue>

using namespace std;
int main(){
	int T; scanf("%d", &T);
	while(T--){
		int k, m, p; scanf("%d %d %d", &k, &m, &p);
		vector<int> d, chk, deg;
		vector<int> e[1001];
		deg.resize(m+1,0);
		d.resize(m+1,-1);
		chk.resize(m+1,0);

		while(p--){
			int u, v; scanf("%d %d", &u, &v);
			deg[v]++;
			e[u].push_back(v);
		}

		queue<int> q;
		for (int i=1; i<=m; i++){
			if( !deg[i]) q.push(i), d[i]=1;
		}

		int ans=0;
		while(!q.empty()){
			int now = q.front(); q.pop();
			int sz = e[now].size();
			for (int i=0; i<sz; i++){
				deg[e[now][i]]--;

				if (d[e[now][i]] < d[now]) {
					d[e[now][i]]= d[now];
					chk[e[now][i]]=1;
				}
				else if ( d[e[now][i]] == d[now] ){
					if(chk[e[now][i]]) d[e[now][i]]= d[now]+1, chk[e[now][i]]=0;
				}

				if (!deg[e[now][i]]){
					q.push(e[now][i]); 
				}
			}
		}
		for (int i=1; i<=m; i++) ans = max(ans, d[i]);
		printf("%d %d\n",k, ans);
	}
}
