#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
struct Maximumflow{
	int n, m;
	vector<vector<int> > e;
	vector<int> pred, chk;
	Maximumflow(int n, int m) : n(n), m(m){
		e.resize(2500); chk.resize(2500);
		pred.resize(2500, -1);
	}

	void add_edge(int u, int v){ e[u].push_back(v); }

	bool dfs(int now){
		if ( now == -1) return 1;
		for (int i=0; i<e[now].size(); i++){
			if ( chk[e[now][i]] ) continue;
			chk[e[now][i]] =1;
			if ( dfs(pred[e[now][i]]) ) {
				pred[e[now][i]]=now;
				return 1;
			}
		}
		return 0;
	}

	int flow(){
		int ans=0;
		for (int i=1; i<=n; i++){
			fill(chk.begin(), chk.end(), 0);
			if (dfs(i)) ans++;
		}
		return ans;
	}

};

char s[50][51];
int a[50][50], b[50][50];
int main(){
	int n, m; scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++) scanf("%s", s[i]);

	int cnt=1;
	for (int i=0; i<n; i++){
		int st=0;
		for (int j=0; j<m; j++){
			if ( s[i][j] == '*' ) a[i][j] = cnt, st=1;
			else if ( st ) cnt++,st=0;
		}
		if (st) cnt++;
	}

	int ccnt=1;
	for (int i=0; i<m; i++){
		int st=0;
		for (int j=0; j<n; j++){
			if ( s[j][i] == '*' ) b[j][i] = ccnt, st=1;
			else if (st) ccnt++, st=0;
		}
		if (st) ccnt++;
	}

	Maximumflow mf(cnt,ccnt);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j]) {
				mf.add_edge(a[i][j],b[i][j]);
			}
		}
	}
	printf("%d\n", mf.flow());

}
