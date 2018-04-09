#include <stdio.h>
#include <vector>

using namespace std;
struct Maximumflow{
	int n;
	vector<vector<int> > e;
	vector<int> pred, chk;
	Maximumflow(int n) : n(n) {
		e.resize(n+1); chk.resize(n+1); pred.resize(n+1, -1);
	}

	void add_edge(int u, int v){ e[u].push_back(v); }

	bool dfs(int now){
		if (now == -1) return 1;

		for (int i=0; i<e[now].size(); i++){
			if (chk[e[now][i]]) continue;
			chk[e[now][i]]=1;
			if ( dfs(pred[e[now][i]] ) ){
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
			if(dfs(i)) ans++;
		}
		return ans;
	}
};

int main(){
	int n, k; scanf("%d %d", &n, &k);
	Maximumflow mf(n);
	while(k--){
		int u, v; scanf("%d %d", &u, &v);
		mf.add_edge(u, v);
	}
	printf("%d\n", mf.flow());

}
