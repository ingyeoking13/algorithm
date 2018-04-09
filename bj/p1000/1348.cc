#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Maximumflow{
	int n;
	vector<vector<int> > e;
	vector<int> chk, pred;

	Maximumflow(int n) : n(n){
		e.resize(n), pred.resize(n,-1), chk.resize(n);
	}

	void add_edge(int u, int v){ e[u].push_back(v); }

	bool dfs(int now){
		if ( now == -1 ) return 1;

		for (int i=0; i<e[now].size(); i++){
			if ( chk[e[now][i]] ) continue;

			chk[e[now][i]]=1;
			if ( dfs(pred[e[now][i]]) ){
				pred[e[now][i]] = now;
			 	return 1;
			}
		}
		return 0;
	}

	int flow(){
		int ans=0;
		for (int i=0; i<n; i++){
			fill(chk.begin(), chk.end(), 0);
			if ( dfs(i) ) ans++;
		}
		return ans;
	}
};

typedef struct{int x,y; }point;
vector<point> car, park;
char s[100][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
	int row, col; scanf("%d %d", &row, &col);

	for (int i=0; i<row; i++) scanf("%s", s[i]);
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if ( s[i][j] == 'C' ) car.push_back({i, j});
			if ( s[i][j] == 'P' ) park.push_back({i, j});
		}
	}

	int time[100][100];
	if ( car.size() == 0) return !printf("0\n");
	if ( park.size() < car.size()) return !printf("-1\n");

	for (int i=0; i<car.size(); i++){
		queue<point> q;
		int dist[50][50]; 
		memset(dist, -1, sizeof(dist));

		point st= car[i];
		q.push(st);
		dist[st.x][st.y]=0;

		while(!q.empty()){
			point now = q.front(); q.pop();
			int x = now.x, y = now.y;

			for (int j=0; j<4; j++){
				int nx = x + dx[j], ny = y+ dy[j];
				if ( nx <row && ny < col && nx>=0 && ny>=0) {
					if ( s[nx][ny] !='X' || dist[nx][ny]>=0) continue;
					dist[nx][ny]=dist[x][y]+1;
					q.push({nx,ny});
				}
			}
		}

		for (int j=0; j<park.size(); j++) time[i][j] = dist[park[j].x][park[j].y];
	}


	int l = 1, r = row*col;
	int ans = row*col+1, im = row*col+1;

	while(l<=r){
		int m = (l+r)/2;
		Maximumflow mf(max(car.size(),park.size()));

		for (int i=0; i<car.size(); i++){
			for (int j=0; j<park.size();j++){
				if ( 0<=time[i][j] && time[i][j] <= m ){
					mf.add_edge(i, j);
				}
			}
		}
		if ( mf.flow() == car.size()){ 
			ans = min(m, ans);
			r= m-1;
		}
		else l=m+1;
	}
	if ( ans == im) return !printf("-1\n");
	printf("%d\n", ans);
}
