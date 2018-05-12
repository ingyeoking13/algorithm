#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

struct Edge{ int v, w; };
vector <Edge> e[500]; // store edge
vector<int> d;
vector<vector<pair<int, int>>> p; // store parent edge

void dfs(int now){
	if ( now == -1) return;

	int sz = p[now].size();
	for (int i=0; i< sz; i++){

		e[p[now][i].first][p[now][i].second].w =-1;  
		dfs(p[now][i].first);

	}
}

int main(){

	int n, m; scanf("%d %d", &n, &m);
	int f, t; scanf("%d %d", &f, &t);

	while(m--){
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		e[u].push_back({v, w});
	}

	p.resize(n), d.resize(n);

	fill(d.begin(), d.end(), 0x3f3f3f3f); // make each d[i] 1 billion...<=>  infinity
	for (int i=0; i<p.size(); i++){
		fill(p[i].begin(), p[i].end(), make_pair(-1, -1));
	}

	priority_queue<pair<int, int> >  pq;

	d[f]=0;
	pq.push({d[f], f});

	while(!pq.empty()){
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if ( cost > d[now] ) continue;

		int sz = e[now].size();
		for (int i=0; i<sz; i++){
			if ( d[e[now][i].v] > cost + e[now][i].w){

				p[e[now][i].v].clear();
				d[e[now][i].v] = cost + e[now][i].w;
				p[e[now][i].v].push_back({now, i});  // we save it path
				pq.push({-d[e[now][i].v], e[now][i].v});
			}
			if ( d[e[now][i].v] == cost + e[now][i].w ){
				p[e[now][i].v].push_back({now, i});  // we save it path
			}
		}
	} // we retrieve shortest path and its length

	dfs(t);

	fill(d.begin(), d.end(), 0x3f3f3f3f); // make each d[i] 1 billion...<=>  infinity

	d[f]=0;
	pq.push({d[f], f});

	while(!pq.empty()){
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if ( cost > d[now] ) continue;

		int sz = e[now].size();
		for (int i=0; i<sz; i++){
			if ( e[now][i].w < 0 ) continue; // ignore if 
			if ( d[e[now][i].v] > cost + e[now][i].w){
				d[e[now][i].v]  = cost + e[now][i].w;
				pq.push({-d[e[now][i].v], e[now][i].v});
			}
		}
	} // we retrieve shortest path length again

	if ( d[t] == 0x3f3f3f3f) printf("-1\n");
	else printf("%d\n", d[t]);
}
