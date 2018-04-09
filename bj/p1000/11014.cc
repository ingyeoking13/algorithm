#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

char a[80][81];
int dx[] = {-1, -1, 0, 0}, dy[] ={-1, 1, -1, 1};

struct Maximumflow{
	int n;
	vector<vector<int> > e;
	vector<int> pred, chk;

	Maximumflow(int n) : n(n){
		e.resize(n), pred.resize(n, -1), chk.resize(n);
	}

	void add_edge(int u, int v){ e[u].push_back(v); }

	bool dfs(int now){
		if ( now == -1 ) return 1;

		for (int i=0; i<e[now].size(); i++){
			if ( chk[e[now][i]]) continue;
			chk[e[now][i]] =1;
			if ( dfs(pred[e[now][i]]) ) {
				pred[e[now][i]] =now;
				return 1;

			}
		}
		return 0;
	}

	int flow(){
		int ans=0;
		for (int i=0; i<n; i++){
			fill(chk.begin(), chk.end(), 0);
			if (dfs(i))  {
				ans++;
			}
		}

		return ans;
	}

};
int main(){

	int T; scanf("%d", &T);
	while(T--){

		int row, col; scanf("%d %d", &row, &col);
		for (int i=0; i<row; i++) scanf("%s", a[i]);

		Maximumflow mf(row*col+1);

		int cnt=0;
		for (int i=0; i<row; i++){
			for (int j=0; j<col; j++){
				int x= i, y =j;
				if (a[x][y] =='x') continue;
				cnt++;

				for (int k=0; k<4; k++){
					int nx = x+dx[k], ny = y+dy[k];
					if ( 0<= nx && 0<= ny && ny < col){
						if ( a[nx][ny] != 'x') {
							if ( (y&1)==0 ) mf.add_edge(x*col+y, nx*col +ny);
							else mf.add_edge(nx*col+ny, x*col+y);
						}
					}
				}
			}
		}

		int ret=mf.flow();
		printf("%d\n", cnt-ret);
	}

}
