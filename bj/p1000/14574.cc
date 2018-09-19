#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct person{ int p, c; };
struct edge{ int u, v , w; };
bool cmp(const edge& a, const edge& b) { return a.w > b.w; }
int p[1001], chk[1001];
person a[1001];
vector<edge> e;
vector<pair<int, int> > ans;

int ufind(int now) {
	if ( p[now] == now) return p[now];
	else return p[now] = ufind(p[now]);
}
int main(){
	int n; scanf("%d", &n);

	for (int i=0; i<n; i++)
		scanf("%d %d", &a[i].p, &a[i].c);

	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			e.push_back({
					i+1, 
					j+1, 
					(a[i].c+a[j].c)/abs(a[i].p-a[j].p)
					});

	sort(e.begin(), e.end(), cmp);
	for (int i=1; i<=n; i++) p[i]=i;

	n = e.size();
	int cost=0;
	for (int i=0; i<n; i++) {
		int u = ufind(e[i].u), v = ufind(e[i].v);
		if (u == v) continue;
		if( chk[e[i].v] ) continue;
		chk[e[i].v]=1;
		p[u] = v;
		cost+=e[i].w;
		ans.push_back({e[i].u, e[i].v});
	}

	printf("%d\n", cost);
	for (auto i: ans){
		printf("%d %d\n", i.first, i.second);
	}
}
