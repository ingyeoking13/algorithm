#include <stdio.h>
#include <algorithm>
using namespace std;

int a[10][10];
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
bool v[10][10];
int ans= 200*100*100+1;
int path[4];

int chkblossom(int x, int y, bool st)
{
  int ret = 0;
  v[x][y]=st; ret+= a[x][y];

  for (int i=0; i<4; i++)
  {
    int nx = x+dx[i], ny = y+dy[i];
    v[nx][ny] =st;
    ret += a[nx][ny];
  }
  return ret;
}

bool canblossom(int x, int y, int n)
{
  bool chk=1;
  if (v[x][y]) return 0;

  for (int i=0; i<4; i++)
  {
    int nx = x+dx[i], ny = y+dy[i];
    if ( 0<= nx && nx < n && 0<= ny && ny< n)
    { 
      if ( v[nx][ny] ) chk=0;
    } else chk=0;
  }
  return chk;
}

void go(int p, int n, int cnt, int cost)
{
  if (cnt == 3) {
    ans=min(ans, cost);
    return ;
  }

  for (int i=p+1; i<n*n; i++)
  {
    if ( canblossom( i/n, i%n, n) )
    {
      int tmp = chkblossom(i/n, i%n, 1);
      path[cnt+1] = i;
      go(i, n, cnt+1, cost + tmp);
      chkblossom(i/n, i%n, 0);
    }
  }
  return ;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i=0; i<n*n; i++)
  {
    if (canblossom(i/n, i%n, n)) 
    {
      int cost = chkblossom(i/n, i%n, 1);
      path[1] = i;
      go(i, n, 1, cost);
      chkblossom(i/n, i%n, 0);
    }
  }
  printf("%d\n", ans);
}
