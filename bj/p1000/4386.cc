#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
  int u, v;
  double w;
  Edge(int u, int v, double w):u(u), v(v), w(w) { };
  bool operator< (Edge b) { return w< b.w; }
};
int p[(int)1e2];
int ufind(int now)
{
  if ( p[now] == now ) return now;
  return p[now] = ufind(p[now]);
}

int main()
{
  int n;
  scanf("%d", &n);

  double x[(int)1e2], y[(int)1e2];

  for (int i=0; i<n; i++)
  {
    scanf("%lf%lf", &x[i], &y[i]);
    p[i]=i;
  }

  vector<Edge> e;
  for (int i=0; i<n; i++)
  {
    for (int j=i+1; j<n; j++)
    {
      double xdiff = (x[i] - x[j]);
      double ydiff = (y[i] - y[j]);

      xdiff*=xdiff;
      ydiff*=ydiff;

      double cost = sqrt(xdiff+ydiff);
      e.push_back( Edge(i,j, cost) );
    }
  }
  sort(e.begin(), e.end());

  double ans = 0;
  for (int i=0; i<e.size(); i++)
  {
    Edge cur = e[i];
    int u = cur.u, v = cur.v;

    u = ufind(u), v = ufind(v);
    if ( u == v) continue;

    ans += cur.w;
    p[u] = v;
  }
  printf("%.2lf\n", ans);


}
