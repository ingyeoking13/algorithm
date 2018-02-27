// 트리에서 가장 큰 지름은...
// 임의의 점에서 가장 먼 곳에서부터
// 그곳에서 가장 먼 곳을 찾으면,
// 트리의 가장 큰 지름을 찾을 수 있다...
#include <bits/stdc++.h>

using namespace std;
vector <pair<int, int> > e[100001];
queue <int> q;
int d[100001], a[2]={1};
int ans;

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		int u; scanf("%d", &u);
		while(1){
			int v; scanf("%d", &v);
			if ( v==-1) break;
			int w; scanf("%d", &w);
			e[u].push_back({v, w});
		}
	}

	for (int i=0; i<2; i++){
		memset(d, 0, sizeof(d));
		d[a[i]]=1;
		q.push(a[i]);

		while(!q.empty()){
			int now = q.front(); q.pop();
			if ( ans < d[now]-1 ) {
				 ans=d[now]-1, a[1]=now; 
			}

			for (int j=0; j<e[now].size(); j++){
				if ( !d[e[now][j].first] ){
					d[e[now][j].first] = d[now]+e[now][j].second;
					q.push(e[now][j].first);
				}
			}
		}
	}
	printf("%d\n",ans);
}
