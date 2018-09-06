#include <stdio.h>
#include <string.h>

char a[120][120];
char cnt[120][120];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
  if (cnt[x][y]>=0) return;

  cnt[x][y]=0;
  int tmp=0;
  for (int i= 0; i<4; i++)
  {
    int nx = x + dx[i], ny = y+dy[i];
    if ( 0 <= nx && nx<120 && 0 <= ny && ny<120)
    {
      if ( a[nx][ny] == 1) dfs(nx, ny);
      else tmp++;
    }
  }
  cnt[x][y]= tmp;
}

int main()
{
  memset(cnt, -1, sizeof(cnt));

  int T;
  scanf("%d", &T);

  while(T--)
  {
    int l, b;
    scanf("%d %d", &l ,&b);

    for (int i=l; i<l+10; i++)
      for (int j=b; j<b+10; j++)
        a[i+1][j+1] =1;
  }

  for (int i=0; i<120; i++)
  {
    for (int j=0; j<120; j++)
    {
      if (a[i][j] == 1)
      {
        dfs(i, j);
      }
    }
  }

  int ans=0;
  for (int i=0; i<120; i++)
  {
    for (int j=0; j<120; j++)
    {
      if (cnt[i][j] >0) ans += cnt[i][j];
    }
  }
  printf("%d\n", ans);

}
