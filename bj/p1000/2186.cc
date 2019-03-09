#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

char map[100][101];
int cnt[100][100][80];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct POS
{
  int x, y, idx;
  POS(int x, int y, int idx) : x(x), y(y), idx(idx) {};
};

int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i=0; i<n;i++)
  {
    scanf("%s", map[i]);
  }

  char str[83];
  scanf("%s", str);
  int len = strlen(str);
  queue<POS> q;

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      if ( map[i][j] == str[0]) {
        q.push(POS(i, j, 0));
        cnt[i][j][0] =1;
      }
    }
  }

  while(!q.empty())
  {
    POS pos = q.front();
    q.pop();
    int x = pos.x;
    int y = pos.y;
    int idx = pos.idx;
    if (idx == len-1 ) { continue; } 

    for (int i=0; i<4; i++)
    {
      for (int j=1; j<=k; j++)
      {
        int nx = x +dx[i]*j, ny = y+dy[i]*j;
        if ( nx <0 || nx >= n || ny <0 || ny >= m ) continue;

        if ( map[nx][ny] != str[idx+1] ) continue;
        if ( cnt[nx][ny][idx+1] ==0) q.push(POS(nx, ny, idx+1));
        cnt[nx][ny][idx+1] += cnt[x][y][idx];
      }
    }
  }

  int ans=0;
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      ans += cnt[i][j][len-1];
    }
  }
  printf("%d\n", ans);

}
