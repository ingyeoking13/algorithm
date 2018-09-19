#include <stdio.h>
#include <vector>
using namespace std;

struct Maximumflow{

	struct Edge{
		int v, capa;
		Edge* rev;
		Edge(int v, int c) : v(v), capa(c){}
	};

	int s, t;
	vector<vector<Edge *> > e;
	vector<int> chk;

	Maximumflow(int n, int m) : s(0), t(n+m+1){ 
		e.resize(n+m+2); chk.resize(n+m+2);
	}

	void add_edge(int u, int v, int c){
		Edge* edge = new Edge(v, c);
		Edge* res = new Edge(u, 0);
		edge->rev = res;
		res->rev = edge;
		e[u].push_back(edge);
		e[v].push_back(res);
	}

	int dfs(int now, int cur){
		chk[now]=1;
		if( now == t) return cur;

		for (int i=0; i<e[now].size(); i++){
			if ( chk[e[now][i]->v] ) continue;
			int ncur = min(cur, e[now][i]->capa);
			if(ncur<=0) continue;
//			printf("%d %d %d\n", now,e[now][i]->v, ncur);
			int f = dfs(e[now][i]->v, ncur); 
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
//			printf("============new\n");
			int f = dfs(0, 98765432);
			if (!f) break;
			ans+=f;
		}
		return ans;
	}

};

int main(){
	int n, m; scanf("%d %d", &n, &m);
	int a;

	Maximumflow mf(n, m);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a);
		mf.add_edge(0, i, a);
	}

	for (int i=1; i<=m; i++) {
		scanf("%d", &a);
		mf.add_edge(n+i, n+m+1, a);
	}

	for (int i=1; i<=m; i++){
		for (int j=1; j<=n; j++){
			scanf("%d", &a);
			mf.add_edge(j,n+i, a);
		}
	}

	printf("%d\n", mf.flow());

}
