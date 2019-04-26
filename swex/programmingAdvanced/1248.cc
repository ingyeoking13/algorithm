#include <iostream>
#include <string.h>
using namespace std;

int p[(int)1e4+1];

int child[(int)1e4+1][2];
int len[(int)1e4+1];

int d[(int)1e4+1];

void go(int now, int depth)
{
  d[now] = depth;

  for (int i=0; i< len[now]; i++) go(child[now][i], depth+1);
}
int getSize(int now)
{
  int ret =1;
  for (int i=0; i<len[now]; i++) 
  {
    ret += getSize(child[now][i]);
  }
  return ret;
}

int main()
{
  int T;
  int tt =0;
  cin >> T;


  while (++tt <= T)
  {
    int n, e, x, y;
    cin >> n >> e >> x >> y;
    memset(len, 0, sizeof(len));

    for (int i=0; i<e; i++)
    {
      int u, v;
      cin >> u >> v;
      p[v] = u;
      child[u][len[u]++] = v;
    }
    go(1, 0);

    while ( d[x] > d[y] ) x = p[x];
    while ( d[x] < d[y] ) y = p[y];
    if ( x == y ) cout << "#" << tt << " " << x << " " << getSize(x) << "\n";
    else
    {
      while ( x != y ) { x=p[x]; y=p[y]; }
      cout << "#" << tt << " " << x << " " << getSize(x) << "\n";
    }
  }
}
