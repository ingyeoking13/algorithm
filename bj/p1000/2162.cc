#include <stdio.h>
#include <vector>

using namespace std;

struct Edge
{
  double x1, y1, x2, y2;
  Edge(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

struct Point
{
  double x, y;
  Point(double x, double y) : x(x), y(y) {}
  bool operator < (const Point& a) { return (x==a.x?y<a.y:x<a.x); }
};

vector<Edge> e;
vector<int> p, sz;

int ufind(int u)
{
  if ( p[u] == u) return u;
  else return p[u] = ufind(p[u]);
}

double outer_product(Point a, Point b, Point c)
{
  double x1 = a.x - b.x; double y1 = a.y - b.y;
  double x2 = b.x - c.x; double y2 = b.y - c.y;
  return x1*y2 - y1*x2;
}

bool intersect(Edge line1, Edge line2)
{
  Point a = Point(line1.x1, line1.y1);
  Point b = Point(line1.x2, line1.y2);
  Point c = Point(line2.x1, line2.y1);
  Point d = Point(line2.x2, line2.y2);

  double ab = outer_product(a,b,c) * outer_product(a,b,d);
  double cd = outer_product(c,d,a) * outer_product(c,d,b);

  if ( ab == 0 && cd == 0)
  {
    if (b<a) { Point tmp =a; a = b; b=tmp; }
    if (d<c) { Point tmp = c; c = d; d = tmp; }
    return !(b<c || d<a);
  }
  return ab <= 0 && cd <= 0;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    e.push_back(Edge(x1, y1, x2, y2));
  }

  p.resize(n);
  sz.resize(n, 1);

  for (int i=0; i<n; i++) p[i]=i;

  for (int i=0; i<n; i++)
  {
    for (int j=i+1; j<n; j++)
    {

      int pi = ufind(i), pj = ufind(j);
      if (pi == pj) continue;

      if (intersect(e[i], e[j]))
      {
        sz[pi] += sz[pj];
        p[pj] = pi;
      }
    }
  }

  int mx=0, cnt=0;
  for (int i=0; i<n; i++)
  {
    if (p[i] == i)
    {
      if ( mx < sz[i] ) mx = sz[i];
      cnt++;
    }
  }
  printf("%d\n%d\n", cnt, mx);
}
