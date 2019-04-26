#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

vector<int> e[(int)1e5];
int p[(int)1e5][20];
int d[(int)1e5];

void go(int now)
{

  for (int i=1; i<20; i++)
  {
    p[ now ][ i ] = p[ p[now][i-1] ][ i-1 ]; 
  }

  for (int i=0; i<e[now].size(); i++)
  {
    if ( p [ e[now][i]  ][0] >= 0) continue;

    p [ e[now][i] ][0] =  now;
    d [ e[now][i] ] = d[ now ] + 1;
    go ( e[now][i] ) ;
  }
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n-1; i++)
  {
    int u,  v;
    scanf("%d%d", &u, &v);
    u--, v--;

    e[u].push_back(v);
    e[v].push_back(u);
  }

  memset(p, -1, sizeof(p));
  for (int i=0; i<20; i++) p[0][i] = 0;
  d[0] = 0;
  go(0);

  int m;
  scanf("%d", &m);
  while(m--)
  {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    if ( d[u] < d[v] ) { u^=v; v^=u; u^=v; }

    for (int i=19; i>=0; i--)
    {
      if ( d[v] <= d[ p[u][i] ] ) u = p[u][i];
    }

    for (int i=19; i>=0; i--)
    {
      if ( p[ u ][ i ] != p[ v ][ i ] )
      {
        u = p[u][i], v = p[v][i];
      }
    }
    if( u== v) printf("%d\n", u+1);
    else printf("%d\n", p[u][0]+1);
  }
}

