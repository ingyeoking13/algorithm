#include <stdio.h>
#include <string.h>
#include <unistd.h>

unsigned char dp[40001][201];
int min (int x, int y) { return x>y?y:x; }
int main()
{

  int n, m, M, T, R;
  scanf("%d %d %d %d %d", &n, &m, &M, &T, &R);

  memset(dp, -1, sizeof(dp));

  dp[0][m]=0;
  int ans=1e9;

  for (int i=1; i<=40000; i++)
  {
    for (int j=0; j<=200; j++)
    {
      if (dp[i-1][j] != 255 )
      {
        if ( j + T <= M ) 
        {
          dp[i][j+T] = dp[i-1][j]+1;
//          printf("%d %d %d %d\n", i, j, dp[i][j+T], dp[i-1][j]);
          if (dp[i][j+T] >= n) 
          {
            ans =min(i, ans);
            goto ret;
          }
        }

        if ( j- R >= m ) dp[i][j-R] = dp[i-1][j];
        else             dp[i][m] = dp[i-1][j];
      }

    }

  }
ret: printf("%d\n", ans ==1e9?-1:ans);
}
