#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct MCMF
{
	struct Edge
	{
		int v, w, capa;
		Edge* rev;
		Edge(int v,int capa, int w) : v(v), capa(capa), w(w) {}
	};

	int s, t;
	vector<vector<Edge *>> e;
	vector<pair<int, int>> p;
	vector<bool> inQ;
	vector<int> d;

	MCMF(int n, int s, int t) : s(s), t(t)
	{
		e.resize(n);
		p.resize(n, make_pair(-1, -1));
		inQ.resize(n);
		d.resize(n);
	}

	void add_edge(int u, int v, int capa, int w)
	{
		Edge* edge = new Edge(v, capa, w);
		Edge* res =  new Edge(u, 0, -w);
		edge->rev = res;
		res->rev = edge;
		e[u].push_back(edge);
		e[v].push_back(res);
	}

	bool spfa(int &cost, int &flow)
	{
		fill(p.begin(), p.end(), make_pair(-1, -1));
		fill(inQ.begin(), inQ.end(), 0);
		fill(d.begin(), d.end(), 0x3f3f3f3f);

		queue<int> q;
		q.push(0);
		d[0]=0;

		while(!q.empty())
		{
			int now = q.front();
			q.pop();
			inQ[now]=0;

			for (int i=0; i<e[now].size(); i++)
			{
				Edge* edge = e[now][i];
				if( edge->capa <=0) continue;

				if ( d[edge->v] > d[now] + edge->w)
				{
					d[edge->v] = d[now]+edge->w;
					p[edge->v] = make_pair(now, i);
					if (!inQ[edge->v]) 
					{
						q.push(edge->v); 
						inQ[edge->v]=1;
					}
				}
			}
		}

		int now = t;
		if ( p[now].first == -1) return 0;
		int mn = e[p[now].first][p[now].second]->capa;
		while(p[now].first != -1 )
		{
			mn = min(e[p[now].first][p[now].second]->capa, mn);
			now = p[now].first;
		}

		now=t;
		while(p[now].first != -1)
		{
			e[p[now].first][p[now].second]->capa -= mn;
			e[p[now].first][p[now].second]->rev->capa += mn;
			now = p[now].first;
		}

		cost += d[t] * mn;
		flow += mn;
		return 1;
	}

	pair<int, int> flow()
	{
		int cost =0, flow=0;
		while(spfa(cost, flow));
		return make_pair(cost ,flow);
	}
};

int main()
{
	while(1)
	{
		int n; scanf("%d", &n);
		if ( n==0 ) break;

		MCMF mcmf(367,0,366);
		while(n--)
		{
			int u, v, w; 
			scanf("%d %d %d", &u, &v, &w);
			mcmf.add_edge(u, v+1, 1, -w);
		}
		for (int i=0; i<=365; i++)
		{
			mcmf.add_edge(i, i+1, 2, 0);
		}
		printf("%d\n", -mcmf.flow().first);
	}
}
