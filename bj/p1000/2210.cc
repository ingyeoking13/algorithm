#include <stdio.h>

char chk[(int)1e7];
int a[5][5];
int b[6];

char dx[4] ={ -1, 1, 0, 0};
char dy[4] ={ 0, 0, -1, 1};

void dfs(int x, int y, int depth)
{
  if (depth==6)
  {
    int now =0;
    for (int i=0; i<6; i++)
    {
      now *= 10;
      now += b[i];
    }
    if (chk[now]==0)
    {
//      printf("%d\n", now);
    }
    chk[now]=1;

    return;
  }

  for (int i=0; i<4; i++)
  {
    int nx = x+dx[i], ny = y+dy[i];
    if ( 0<= nx && nx<5 && 0<= ny && ny< 5)
    {
      b[depth]=a[nx][ny];
      dfs(nx, ny, depth+1);
    }
  }
}

int main()
{

  for (int i=0; i<5; i++)
    for (int j=0; j<5; j++)
      scanf("%d", &a[i][j]);


  for (int i=0; i<5; i++)
  {
    for (int j=0; j<5; j++)
    {
      dfs(i, j, 0);
    }
  }
  int ans=0;
  for (int i=0; i<(int)1e7; i++)
  {
    if (chk[i]) ans++;
  }
  printf("%d\n", ans);

}
