#include <stdio.h>
#include <stack>
#include <algorithm>

using namespace std;

struct Point
{
  int x, y;
  int p, q;
  Point() { x= y = p = q = 0; }
  Point(int x, int y ) : x(x), y(y) { p = q = 0; }

  bool operator < (const Point& b) 
  {
    long long pp = p, qq = q;
    long long val = pp * b.q - qq * b.p;
    if ( val != 0) return val > 0;

    if( x == b.x ) return y < b.y;
    return x < b.x;

  }
};

Point p[(int)1e5];

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i] = Point(x, y);
  }

  sort(p, p+n);
  for (int i=1; i<n; i++)
  {
    p[i].p = p[i].x - p[0].x;
    p[i].q = p[i].y - p[0].y;
  }
  sort(p+1, p+n);

  stack<int> s;
  s.push(0); s.push(1);
  int i = 2;
  while ( i < n)
  {
    while (s.size() >= 2)
    {
      int mid = s.top();
      s.pop();
      int start = s.top();

      int dx = p[mid].x- p[start].x;
      int dy = p[mid].y- p[start].y;
      int ddx = p[i].x - p[mid].x;
      int ddy = p[i].y - p[mid].y;

      if ( (long long)dx*ddy - (long long)dy*ddx >0 )
      {
        s.push(mid);
        break;
      }
    }
    s.push(i++);
  }
  printf("%lu\n", s.size());
}
