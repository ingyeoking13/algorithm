#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
struct Maximumflow{
	struct Edge{
		int v, capa;
		Edge* rev;
		Edge(int v, int capa): v(v), capa(capa) {}
	};

	int n, s, t;
	vector<vector<Edge *> > e;
	vector<bool> chk;
	Maximumflow(int n, int s, int t): n(n), s(s), t(t){
		e.resize(n); chk.resize(n);
	}

	void add_edge(int u, int v, int f){
		Edge* edge = new Edge(v, f); 
		Edge* res = new Edge(u, 0); 
		edge->rev = res;
		res->rev = edge;
		e[u].push_back(edge);
		e[v].push_back(res);
	}

	int dfs(int now, int cur){
		if ( now == t ) return cur;
		for (int i=0; i<e[now].size(); i++){
			if ( chk[e[now][i]->v] ) continue;
			if ( e[now][i]->capa <=0 ) continue;

			chk[e[now][i]->v]=1;
			int newcur = min(e[now][i]->capa,cur);

			int f=dfs(e[now][i]->v, newcur);
			if (f){
				e[now][i]->capa -= f;
				e[now][i]->rev->capa += f;
				return f;
			}
		}
		return 0;
	}

	int flow(){
		int ans=0;
		while(1){
			fill(chk.begin(), chk.end(), 0);
			chk[s]=1;
			int f = dfs(s, 9875432);
			if ( !f ) break;
			ans+=f;
		}
		return ans;
	}

};

char s[100][101];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int row, col;
int node(int x, int y, bool type){ return 2*(x*col+y)+type; }
int main(){
	scanf("%d %d", &row, &col);
	int sx, sy, ex, ey;
	for (int i=0; i<row; i++) {
		scanf("%s", s[i]);
		for (int j=0; j<col; j++) {
			if ( s[i][j] == 'K' ) sx=i, sy=j;
			else if ( s[i][j] == 'H') ex=i, ey=j;
		}
	}

	Maximumflow mf(2*row*col+1,
								node(sx,sy,1),
								node(ex,ey,0));

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if ( s[i][j] == '#') continue;

			int x = i, y = j;
			mf.add_edge(node(x,y,0), node(x,y,1), 1);
			for (int k=0; k<4; k++){
				int nx = x+dx[k], ny = y+dy[k];
				if ( 0<= nx && nx < row && 0<= ny && ny < col){
					if ( s[nx][ny] == '#') continue;
					mf.add_edge(node(x,y,1),node(nx,ny,0), 10000);
				}
			}
		}
	}
	printf("%d\n", mf.flow());

}
