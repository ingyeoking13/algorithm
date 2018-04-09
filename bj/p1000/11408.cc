#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Maximumflow{
	struct Edge{
		int v, capa, cost;
		Edge* rev;
		Edge(int v, int ca, int co) : 
			v(v), capa(ca), cost(co){}
	};

	int s, t;
	vector<vector<Edge*> > e;
	vector<int> chk, d;
	vector<pair<int, int> > p;

	Maximumflow(int n, int s, int t) : s(s), t(t){
		e.resize(n), d.resize(n); 
		chk.resize(n), p.resize(n);
	}

	void add_edge(int u, int v, int capa, int cost){
		Edge* edge = new Edge(v, capa, cost);
		Edge* res = new Edge(u, 0, -cost);
		edge->rev = res;
		res->rev = edge;
		e[u].push_back(edge);
		e[v].push_back(res);
	}

	bool spfa(int &flow, int &cost){
		fill(chk.begin(), chk.end(), 0);
		fill(d.begin(), d.end(), 0x3f3f3f3f);
		fill(p.begin(), p.end(), make_pair(-1,-1));

		queue<int> q;
		d[s]=0;
		q.push(s);

		while(!q.empty()){
			int now = q.front(); q.pop(); 
			chk[now]=0;

			for (int i=0; i<e[now].size(); i++){
				if ( e[now][i]->capa <= 0 ) continue;
				int v = e[now][i]->v;
				if ( d[v] > e[now][i]->cost + d[now]){
					d[v] = e[now][i]->cost+d[now];
					p[v] = make_pair(now, i);
					if (!chk[v]) q.push(v), chk[v]=1;
				}
			}
		}

		if (d[t] == 0x3f3f3f3f) return 0;

		int now =t;
		int mn = e[p[now].first][p[now].second]->capa;

		while( p[now].first != -1){
			mn = min(e[p[now].first][p[now].second]->capa, mn);
			now = p[now].first;
		}

		now =t;
		while(p[now].first != -1){
			e[p[now].first][p[now].second]->capa -= mn;
			e[p[now].first][p[now].second]->rev->capa += mn;
			now = p[now].first;
		}

		flow += mn;
		cost += mn*d[t];

		return 1;
	}

	pair<int, int> flow(){
		int flow=0, cost=0;
		while(spfa(flow, cost));
		return make_pair(flow, cost);
	}
};

int main(){
	int n, m; scanf("%d %d", &n, &m);

	Maximumflow mf(n+m+2, 0, n+m+1);

	for (int i=1; i<=n; i++){
		mf.add_edge(0, i, 1, 0);
		int tmp; scanf("%d", &tmp);
		while(tmp--){
			int v, w;
			scanf("%d %d", &v, &w);
			mf.add_edge(i, n+v, 1, w);
		}
	}
	for (int i=1; i<=m; i++) mf.add_edge(n+i, n+m+1, 1, 0);

	pair<int, int> ans = mf.flow();
	printf("%d\n%d\n", ans.first, ans.second);

}
