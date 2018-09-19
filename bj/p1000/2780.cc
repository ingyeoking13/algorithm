#include <stdio.h>
#include <string.h>
#include <unistd.h>

char a[4][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 0, 0}};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dp[10][1001];

int go (int now, int depth)
{
  if ( dp[now][depth] >=0 ) return  dp[now][depth];

  int x= now/3, y=now%3;
  dp[now][depth] = 0;
  for (int i=0; i<4; i++)
  {
    int nx = x +dx[i], ny = y+dy[i];
    if ( 0<= nx && nx <4 && 0<=ny && ny<3)
    {
      if (a[nx][ny])
      {
        int next = nx*3+ny;
        dp[now][depth] = (dp[now][depth]%1234567 + go(next, depth-1)%1234567)%1234567;
      }
    }
  }
  return dp[now][depth];
}

int main()
{
  memset(dp, -1, sizeof(dp));
  for (int i=0; i<=10; i++) dp[i][1]=1;
  for (int i=0; i<4; i++)
  {
    for (int j=0; j<3; j++)
    {
      for (int k=1; k<=1000; k++)
      {
        if (a[i][j])
        {
          int now = i*3 + j;
          go(now, k);
        }
      }
    }
  }

  int T;
  scanf("%d", &T);
  while(T--)
  {
    int n;
    scanf("%d", &n);
    int ans=0;
    for (int i=0; i<=9; i++) ans=  (ans%1234567 +dp[i][n]%1234567)%1234567;
    printf("%d\n", ans);
  }
}
