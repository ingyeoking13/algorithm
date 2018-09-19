#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
  int n, m, mx=0; long long ans=-1;
  int a[9][9];
  char v[9][9], route[9];

  scanf("%d %d", &n, &m);
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      scanf("%1d", &a[i][j]);
    }
  }

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      for (int k=-9; k<=9; k++)
      {
        for (int l=-9; l<=9; l++)
        {
          memset(v, 0, sizeof(v));
          memset(route, 0, sizeof(route));

          int bx = i, by = j, len=0;
          v[bx][by]=1;
          route[len++]= a[bx][by];
          if ( route[0] > ans  && (route[0] == 0 || route[0] == 1 || route[0]==4 || route[0] == 9)) 
          {
            ans = route[0];
          }

          while( 0<= bx+k  && bx+k <= n-1 && 0<= by+l && by+l <= m-1 && !v[bx+k][by+l] )
          {
            v[bx + k][by + l]=1;
            route[len++] = a[bx+k][by+l];

            long long tmp=0;
            for (int o = 0; o<len ;o++)
            {
              tmp *= 10L;
              tmp += (long long)route[o];
            }

            long long now = sqrt(tmp);
            if ( now*now == tmp)
            {
              if ( tmp > ans ) 
              {
                mx = len;
                ans = tmp;
              }
            }

            bx+= k; by+= l;
          }
        }
      }
    }
  }
  printf("%lld\n", ans);

}
