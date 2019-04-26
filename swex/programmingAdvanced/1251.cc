#include <iostream>
#include <algorithm>
using namespace std;

struct point
{
  int x, y;
  point() {};
};
struct Edge
{
  long long len;
  int u, v;
  Edge() {};
  Edge(int u, int v, long long len ) :u(u), v(v), len(len) {};
  bool operator<(Edge b) { return len < b.len; }
};
int p[(int)1e3];
Edge edges[(int)1e6];

bool mycmp(const Edge& aa, const Edge& bb)
{
  return aa.len < bb.len;
}
int ufind(int now)
{
  if ( now == p[now] ) return now;
  return p[now] = ufind(p[now]);
}

int main()
{
  int tt=0;
  int T;
  cin >> T;
  point a[(int)1e3];

  int edgeNum;

  while (++tt<= T)
  {
    edgeNum=0;

    int n;
    cin >> n;

    for (int i=0; i<n; i++) cin >> a[i].x; 
    for (int i=0; i<n; i++) cin >> a[i].y; 
    for (int i=0; i<n; i++) p[i] = i;
    double ee;
    cin >> ee;

    for (int i=0; i<n; i++)
    {
      for (int j=i+1; j<n; j++)
      {
        long long len = 
          ((long long)(a[i].x-a[j].x))*(a[i].x-a[j].x) + ((long long)(a[i].y-a[j].y))*(a[i].y-a[j].y);
        edges[edgeNum++] = Edge(i, j, len);
      }
    }

    sort(edges, edges+edgeNum, mycmp);
    double ans = 0;
    for (int i=0; i<edgeNum; i++)
    {
      Edge cur = edges[i];
      int u = cur.u, v = cur.v;
      u = ufind(u), v = ufind(v);
      if ( u == v ) continue;
      p[u] =v;
      ans += (cur.len*ee);
    }
    long long lll = ans*10;
    lll+=5;
    lll/=10;
    cout << "#" << tt << " " << lll <<"\n";
  }
}

