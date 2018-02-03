#include <bits/stdc++.h>

using namespace std;
typedef struct{int i, sec; }water;
int v[201];
int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n, k; scanf("%d %d", &n, &k);
		queue<water> q;
		memset(v, 0, sizeof(v));

		while (k--){
			int tmp; scanf("%d", &tmp);
			q.push({tmp, 1});
			v[tmp]=1;
		}

		while(!q.empty()){
			water now= q.front(); q.pop();
			if ( 0 <now.i -1 && !v[now.i-1]){
				q.push({now.i-1, now.sec+1});
				v[now.i-1]+=now.sec+1;
			}
			if ( now.i < n && !v[now.i+1] ){
				q.push({now.i+1, now.sec+1});
				v[now.i+1]+=now.sec+1;
			}
		}

		int ans=0;
		for (int i=1; i<=n; i++) ans= max(ans, v[i]);
		printf("%d\n", ans);
	}
}
