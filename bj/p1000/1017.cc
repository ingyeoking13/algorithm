#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int a[50], p[2001]= {1, 1};
vector<int> ans;
vector<int> vodd, veven;

int odd(int x, int y){ if ( x&1 ) return x; return y; }
int even(int x, int y){ if ( x&1 ) return y; return x; }

int poss(int x, int y){
	if (x&1 == 0 && y&1 == 0) return 0;
	if (x&1 && y&1 ) return 0;
	return 1;
}

struct Maximumflow{
	int n;
	vector<vector<int> > e;
	vector<int> chk, pred;

	Maximumflow(int n): n(n){
		e.resize(1001); chk.resize(1001); pred.resize(1001,-1);
	};

	void add_edge(int u, int v){
		if ( p[u+v] ) return ;
		int od = odd(u, v), ev = even(u, v);

		e[od].push_back(ev);
	}

	bool dfs(int now, int m2){
		if (now == - 1) return 1;

		for (int i=0; i< e[now].size(); i++){
			if ( chk[e[now][i]] ) continue;
			if ( e[now][i] == m2) continue;
			chk[e[now][i]]=1;

			if( dfs(pred[e[now][i]], m2)){
				pred[e[now][i]] = now;
				return 1;
			}
		}
		return 0;
	}

	void flow(int m1, int m2){
		if ( p[m1+m2] ) return ;
		fill(pred.begin(), pred.end(), -1);
		int ret=0;
		int od = odd(m1, m2);
		int ev = even(m1, m2);
//		printf("%d %d====\n", m1, m2);

		for (int i=0; i<vodd.size(); i++){
			if ( od == vodd[i] ) continue;

			fill(chk.begin(), chk.end(), 0);
			if ( dfs(vodd[i], ev) ) ret++;

		}

//		printf("%d %d\n", m2, ret);
		if (ret == n/2-1)  ans.push_back(m2);
	}
};

int main(){

	for (int i=2; i<=2000; i++) {
		if ( !p[i] ){
			for (int j=i+i; j<=2000; j+=i){
				p[j]=1;
			}
		}
	}
	freopen("in.in", "r", stdin);

	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		if ( a[i]&1 ) vodd.push_back(a[i]);
		else veven.push_back(a[i]);
	}
	Maximumflow mf(n);


	for (int i=0; i<vodd.size();i++){
		for (int j=0; j<veven.size(); j++){
			mf.add_edge(vodd[i], veven[j]);
		}
	}

	if ( a[1] & 1 ){
		for (int i=0; i<veven.size(); i++) mf.flow(a[1], veven[i]);
	}
	else {
		for (int i=0; i<vodd.size(); i++) mf.flow(a[1], vodd[i]);
	}

	if ( ans.size() == 0) return !printf("-1\n");

	sort(ans.begin(), ans.end());
	for (int i=0; i<ans.size(); i++) printf("%d ", ans[i]);
	printf("\n");
}
