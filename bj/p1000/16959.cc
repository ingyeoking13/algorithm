#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define HORSE 1
#define BISHOP 2
#define ROOK 3

int n;
int map[10][10], d[10][10][3];
int hdx[8] = {2, 2, -2, -2, 1, 1, -1, -1}, hdy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int bdx[4] = {-1, -1, 1, 1}, bdy[4] = {-1, 1, -1, 1};
int rdx[4] = {-1, 0, 1, 0}, rdy[4] = {0, 1, 0, -1};

void go (int x, int y, int dist, int st)
{
  d[x][y][st] = dist;

  for (int i=0; i<3; i++)
  {
    if ( i == HORSE)
    {
      for (int j=0; j<8; j++)
      {
        int nx = x+ hdx[j], ny = y+hdy[j];
        if ( nx < 0 || nx >= n || ny <0 || ny >= n) continue;

        int nextdist = dist + (i==st?1:2);
        if ( d[nx][ny][st] <= nextdist) continue; 
        go (nx, ny, nextdist, i);
      }
    }
    else if ( i== BISHOP)
    {
      for (int j=0; j<4; j++)
      {

        int nx= x+bdx[j], ny =y+bdy[j];
        int nextdist = dist + (i==st?1:2);
        while(nx>= 0 && nx< n && ny >= 0 && ny<n)
        {
          if (d[nx][ny][st]  <= nextdist) continue;
          go (nx, ny, nextdist, i);
          nx += bdx[j], ny += bdy[j];
        }
      }
    }
    else
    {
      for (int j=0; j<4; j++)
      {

        int nx= x+bdx[j], ny =y+bdy[j];
        int nextdist = dist + (i==st?1:2);
        while(nx>= 0 && nx< n && ny >= 0 && ny<n)
        {
          if (d[nx][ny][st]  <= nextdist) continue;
          go (nx, ny, nextdist, i);
          nx += rdx[j], ny += rdy[j];
        }
      }
    }
  }
}

int main()
{
  scanf("%d", &n);

  int sx, sy,ex, ey;
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      scanf("%d", &map[i][j]);
      if (map[i][j] == 1)  sx=i, sy=j;
      else if ( map[i][j] == n*n) ex=i, ey=j;
    }
  }
  memset(d, 0x7f7f7f7f, sizeof(d));

  go(sx, sy, 0, HORSE);
  go(sx, sy, 0, BISHOP);
  go(sx, sy, 0, ROOK);

  printf("%d\n", min({d[ex][ey][0], d[ex][ey][1], d[ex][ey][2]}));
}
