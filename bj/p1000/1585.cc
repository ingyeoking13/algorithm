#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
struct Maximumflow{
	struct Edge{
		int v, capa, cost;
		Edge* rev;
		Edge(int v, int c, int co) : v(v), capa(c), cost(co){}
	};

	int n, s, t;
	vector<vector<Edge* > >  e;
	vector<int> chk, d;
	vector<pair<int, int> > p;

	Maximumflow(int n, int s, int t) : n(n), s(s), t(t){
		e.resize(n), chk.resize(n);
		d.resize(n), p.resize(n);
	};

	void add_edge(int u, int v, int capa, int cost){
		Edge* edge = new Edge(v, capa, cost);
		Edge* res = new Edge(u, 0, -cost);
		edge->rev = res;
		res->rev = edge;
		e[u].push_back(edge);
		e[v].push_back(res);
	};

	bool spfa(int& flow, int& cost){
		fill(chk.begin(), chk.end(), 0);
		fill(d.begin(), d.end(), 0x3f3f3f3f);
		fill(p.begin(), p.end(), make_pair(-1, -1));

		queue<int> q;
		d[s]=0;
		q.push(s);

		while(!q.empty()){
			int now = q.front(); q.pop();
			chk[now]=0;

			for (int i=0; i<e[now].size(); i++){
				if(e[now][i]->capa <=0 ) continue;
				int v = e[now][i]->v;

				if (d[v] > e[now][i]->cost+d[now]){
					d[v] = e[now][i]->cost+d[now];
					p[v] = make_pair(now, i);
					if (!chk[v]) q.push(v), chk[v]=1;
				}
			}
		}
		if (d[t] == 0x3f3f3f3f) return 0;

		int now = t;
		int mn = 0x3f3f3f3f;
		while(p[now].first != -1 ){
			mn = min (mn, e[p[now].first][p[now].second]->capa);
			now = p[now].first;
		}

		now = t;
		while(p[now].first != -1){
			Edge* edge = e[p[now].first][p[now].second];
			edge->capa -= mn;
			edge->rev->capa += mn;
			now = p[now].first;
		}

		flow += mn;
		cost += mn*d[t];
		return 1; 
	};

  pair<int, int> flow(){
		int flow=0, cost=0; 
		while(spfa(flow, cost));
    return make_pair(flow, cost);
	}
};

int main(){
	int n; scanf("%d", &n);
	int st[51], et[51];

	Maximumflow mf(2*n+2, 0, 2*n+1);
	Maximumflow mf2(2*n+2, 0, 2*n+1);

	for (int i=1; i<=n; i++) {
		scanf("%d", &st[i]);
		mf.add_edge(0, i, 1, 0);
		mf2.add_edge(0, i, 1, 0);
	}
	for (int i=1; i<=n; i++) {
		scanf("%d", &et[i]);
		mf.add_edge(n+i, 2*n+1, 1, 0);
		mf2.add_edge(n+i, 2*n+1, 1, 0);
	}

	int ptime, ppay;
	scanf("%d %d", &ptime, &ppay);
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (st[i]< et[j] && et[j] -st[i] <ptime ){
				int cost = (ptime-et[j]+st[i])*(ptime-et[j]+st[i]);
				mf.add_edge(i, n+j, 1, min(cost, ppay)); 
				mf2.add_edge(i, n+j, 1, -min(cost, ppay)); 
			}
			else if (st[i]< et[j]) {
				mf.add_edge(i, n+j, 1, 0);
				mf2.add_edge(i, n+j, 1, 0);
			}
		}
	}

	pair<int, int> ans = mf.flow();
	pair<int, int> ans2 = mf2.flow();

	if ( ans.first !=n) return !printf("-1\n");
	else printf("%d %d\n",ans.second,-ans2.second);
}
