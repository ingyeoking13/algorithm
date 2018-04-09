#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string.h>

using namespace std;
typedef struct { double x, y; } point;
point a[100], b[100];

struct Maximumflow{
	int n;
	vector<vector<int> > e;
	vector<int> pred, chk;

	Maximumflow(int n) : n(n){
		e.resize(n), chk.resize(n), pred.resize(n,-1);
	}

	void add_edge(int u, int v) { e[u].push_back(v);}

	bool dfs(int now){
		if ( now == -1 ) return 1;

		for (int i=0; i<e[now].size(); i++){
			if ( chk[e[now][i]] ) continue;
			chk[e[now][i]] = 1;
			if ( dfs(pred[e[now][i]] ) ) {
				pred[e[now][i]] =now;
				return 1;
			}
		}
		return 0;
	}

  int flow(){
		int ans =0;
		for (int i=0; i<n; i++){
			fill(chk.begin(), chk.end(), 0);
			if ( dfs(i) ) ans++;
		}
		return ans;
	}

};

int main(){
	int n, m, s, v; scanf("%d %d %d %d", &n, &m, &s, &v);
	Maximumflow mf(max(n, m));

	for (int i=0; i<n; i++) scanf("%lf %lf", &a[i].x, &a[i].y);
	for (int i=0; i<m; i++) scanf("%lf %lf", &b[i].x, &b[i].y);

	for (int i=0;i<n; i++){
		for (int j=0; j<m; j++){
			double dist = (a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y);
			if ( dist <= s*s*v*v) mf.add_edge(i, j);
		}
	}

	printf("%d\n", mf.flow());
}
