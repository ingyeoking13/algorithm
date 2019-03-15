#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
struct Edge
{
  int u, v, w, cnt, idx;
  Edge(int u, int v, int w, int i) : u(u), v(v), w(w), cnt(0), idx(i) {}
};

vector<Edge> e[(int)3e5+1];

bool mycomp(struct Edge a, struct Edge b)
{
  return a.cnt > b.cnt;
}

int main()
{
  int n, m, k;
  scanf("%d%d%d",&n, &m, &k);

  for (int i=1; i<=m; i++)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    e[u].push_back(Edge(u, v, w, i));
    e[v].push_back(Edge(v, u, w, i));
  }

  vector<long long> dist(n+1, 1e18+9);
  vector<int> pre(n+1,-1);
  vector<int> ans;

  priority_queue<pair<long long, int>> pq;
  dist[1]=0;
  pq.push({0, 1});

  int cnt=0;
  while(!pq.empty() && cnt <k)
  {
    long long cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if (cost > dist[now]) continue;

    if (pre[now] != -1)
    {
      cnt++;
      ans.push_back(pre[now]);
    }


    for (int i=0; i<e[now].size(); i++)
    {
      int next =e[now][i].v;
      if (dist[next] > (long long)cost + e[now][i].w)
      {
        dist[next] = (long long)cost+ e[now][i].w;
        pre[next] = e[now][i].idx;
        pq.push({-dist[next], next});
      }
    }
  }

  printf("%d\n", ans.size());
  for (auto i : ans) printf("%d ", i);
   printf("\n");
}
