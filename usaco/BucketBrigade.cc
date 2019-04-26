#include <stdio.h>
#include <queue>
using namespace std;

int dx[4] ={0, 0, -1, 1};
int dy[4] ={-1, 1, 0, 0};
int v[10][10];

int main()
{
  freopen("buckets.in", "r", stdin);
  char s[10][11];
  int fx, fy, lx, ly;
  for (int i=0; i<10; i++)
  {
    scanf("%s", s[i]);
    for (int j=0; j<10; j++)
    {
      if ( s[i][j] == 'B')
      {
        fx = i, fy=j;
      }
      else if ( s[i][j] == 'L' )
      {
        lx = i, ly = j;
      }
    }
  }

  queue<pair<int, int> > q;
  q.push({fx, fy});

  while(!q.empty())
  {
    auto cur  = q.front();
    q.pop();
    int x = cur.first;
    int y = cur.second;
    for (int i=0; i<4 ; i++)
    {
      int nx = x +dx[i], ny = y+dy[i];
      if ( nx <0 || nx > 10 || ny < 0 || ny > 10 ) continue;
      if ( s[nx][ny] == 'R' || s[nx][ny]=='F') continue;
      if ( v[nx][ny] ) continue;
      v[nx][ny] = v[x][y]+1;
      q.push({nx,ny});
    }
  }

  freopen("buckets.out","w", stdout);
  printf("%d\n", v[lx][ly]-1);
}
