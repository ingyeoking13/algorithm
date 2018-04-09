#include <stdio.h>
#include <vector>

using namespace std;
typedef struct { int x, y, z; }shark;
shark a[1001];

struct Maximumflow{
	int n;
	vector<vector<int> > e;
	vector<int> chk, pred;

	Maximumflow(int n): n(n){
		e.resize(n+1); chk.resize(n+1); pred.resize(n+1, -1);
 	};

	void add_edge(int u, int v){ e[u].push_back(v); }

	bool dfs(int now){
		if ( now == -1 ) return 1;

		for (int i=0; i<e[now].size(); i++){
			if ( chk[e[now][i]] ) continue;
			chk[e[now][i]] = 1;

			if ( dfs(pred[e[now][i]]) ) {
				pred[e[now][i]] = now;
				return 1;
			}
		}
		return 0;

	}

	int flow(){
		int ans=0;

		for (int j=0; j<2; j++){
			for (int i=0; i<n; i++){
				fill(chk.begin(), chk.end(), 0);
				if (dfs(i)) ans++;
			}
		}

		return ans;
	}

};

int main(){
	int n; scanf("%d", &n);
	Maximumflow mf(n);
	for (int i=0; i<n; i++){
		scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if ( i==j ) continue;
			if ( a[i].x == a[j].x && a[i].y == a[j].y && a[i].z == a[j].z){
				if ( i<j ) mf.add_edge(i, j);
			}
			else if ( a[i].x>= a[j].x && a[i].y >= a[j].y && a[i].z>= a[j].z ){
				mf.add_edge(i, j);
			}
		}
	}
	printf("%d\n", n-mf.flow());
}
