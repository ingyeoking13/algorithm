#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

struct Pos
{
  int x, y;
  Pos(int x, int y ) : x(x), y(y) {}
  bool operator< (const Pos& a) const { return x < a.x; }
};

vector<Pos> v;
int d[(int)1e4];
//int seg[(int)1e4*4];

/*
int query(int qf, int qt, int idx, int f, int t)
{
  if ( qf <= f && t <= qt )  return seg[idx];
  if ( qf > t || qt < f) return -1;

  int m = (f+t)/2;
  return max(query(qf, qt, idx*2+1, f, m), query(qf, qt, idx*2+2, m+1, t));
}
*/

/*
int cost(int f, int t)
{
  //int mxh = query(f, t, 0, 0, v.size()-1);
  int mxh;
  if (mxh*2 >= v[t].x - v[f].x) return mxh*2;
  return v[t].x-v[f].x;
}
*/

int go(int now)
{
  if ( now<0 ) return 0;

  if ( d[now]>=0 ) return d[now];

  d[now]=1e9;

  int mxh=abs(v[now].y);
  for (int i=now; i>=0; i--)
  {
    mxh =max( abs(v[i].y), mxh);
    int cost = max(mxh*2 ,v[now].x- v[i].x);
    d[now] = min(go(i-1) + cost, d[now]);
  }
  return d[now];
}

/*
int build(int f, int t, int idx)
{
  if ( f== t) return seg[idx] = abs(v[f].y);
  int m = (f+t)/2;
  return seg[idx] = max(build(m+1, t, idx*2+2), build(f, m, idx*2+1));
}
*/

int main()
{
  int n;
  cin >> n;
  for (int i=0; i<n; i++)
  {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }

  memset(d,-1,sizeof(d));
  sort(v.begin(), v.end());
 // build(0, n-1, 0);
  cout << go( n-1) << "\n";
}
