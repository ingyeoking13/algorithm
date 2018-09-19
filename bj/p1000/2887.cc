#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct Pos{ int x, y, z, i; };
struct Edge{ int u, v, w; };
bool cmpx(const Pos& a, const Pos& b) { return a.x > b.x; }
bool cmpy(const Pos& a, const Pos& b) { return a.y > b.y; }
bool cmpz(const Pos& a, const Pos& b) { return a.z > b.z; }
bool cmpe(const Edge& a, const Edge& b) {return a.w < b.w;}

vector<Pos> a;
vector<Edge> e;
int p[100000];

int ufind(int now)
{
	if (p[now] == now) return now;
	else return p[now] = ufind(p[now]);
}

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		int x, y, z; 
		scanf("%d %d %d", &x, &y, &z);
		a.push_back({x, y, z, i});
		p[i]=i;
	}

	sort(a.begin(), a.end(), cmpx);
	for (int i=0; i<n-1; i++)
		e.push_back({a[i].i, a[i+1].i, a[i].x-a[i+1].x});

	sort(a.begin(), a.end(), cmpy);
	for (int i=0; i<n-1; i++)
		e.push_back({a[i].i, a[i+1].i, a[i].y-a[i+1].y});

	sort(a.begin(), a.end(), cmpz);
	for (int i=0; i<n-1; i++)
		e.push_back({a[i].i, a[i+1].i, a[i].z-a[i+1].z});

	sort(e.begin(), e.end(), cmpe);
	n = e.size();
	int ans=0;
	for (int i=0; i<n; i++)
	{
		int u = e[i].u, v = e[i].v;
		u = ufind(u), v = ufind(v);
		if ( u == v) continue;
		p[u]=v;
		ans += e[i].w;
	}
	printf("%d\n", ans);

}
