#include <bits/stdc++.h>

using namespace std;
typedef struct{int v, w;}node;
int d[125*125], a[125][125], cnt;
int dx[4] = {-1, 1, 0, 0}, dy[4] = { 0, 0, -1, 1};
vector<node> e[125*125];
priority_queue< pair<int, int> > pq;
int main(){

	while(1){
		int n; scanf("%d", &n); if(!n) break;

		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				scanf("%d", &a[i][j]);
		for (int i=0; i<n*n; i++) e[i].clear();

		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				for (int k=0; k<4; k++){
					int nx = i+dx[k], ny =j+dy[k];
					if ( 0 <= nx && nx <n && 0 <= ny && ny <n){
						e[i*n+j].push_back({nx*n+ny, a[nx][ny]});
					}
				}
			}
		}

		for (int i=0; i<n*n; i++) d[i] = 125*125*9+1;
		d[0]=a[0][0];
		pq.push(make_pair(-d[0], 0));
		while(!pq.empty()){
			int cost = -pq.top().first;
		 	int now = pq.top().second;	
			pq.pop();
			if ( d[now] < cost ) continue;

			for (int i=0; i<e[now].size(); i++){

				if ( d[e[now][i].v] > d[now] + e[now][i].w){
					d[e[now][i].v] = d[now] + e[now][i].w;
					pq.push(make_pair(-d[e[now][i].v], e[now][i].v));
				}
			}
		}
		
		cnt++;
		printf("Problem %d: %d\n", cnt, d[n*n-1]);
	}
}
