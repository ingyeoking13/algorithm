#include <stdio.h>

int hp[200000];
int dam[200000];

struct MCMF{
	struct Edge{
		int to, capa, d;
		Edge* rev;
		Edge(int to, int c, int d) : to(to), capa(c), d(d) {}
	};
	int s, t; 
	vector<int> chk, dist;
	vector<vector<Edge *> > e;
	vector<pair<int, int>> p;

	MCMF(int n, int s, int t) : s(s), t(t){
		chk.resize(n), dist.resize(n),
		e.resize(n), p.resize(n);
	}

	void add_edge(int u, int v, int capa, int dist){
		Edge* edge = new Edge(v, capa, dist);
		Edge* res = new Edge(u, 0, -dist);
		edge->rev = res;
		res->rev = edge;
		e[u].push_back(edge);
		e[v].push_back(res);
	}

	bool 


};

int main(){
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	MCMF mf(n+3, n+1, n+2);

	for (int i=1; i<=n; i++){ 
		scnaf("%d\n", hp[i]);
		scnaf("%d\n", dam[i]);
	}

	mf.add_edge(n+1, 0, 20, 0);
	for (int i=1; i<=n; i++){
		mf.add_edge(0, i, 20, -hp[i]);
		mf.add_edge(i, n+2, 20, 0);
	}

	mf.flow();
}
