#include <stdio.h>

int a[(int)1e3][(int)1e3];
int dx[4] ={-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int abs(int n) { return n>0?n:-n;};
int max(int x, int y) { return x>y?x:y;};
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++) scanf("%d", &a[i][j]);
  }

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      int x= i, y= j;
      int mncnt[4] = {0, 0, 0, 0}, mxcnt[4] = {0,0, 0, 0};

      for (int k=0; k<4; k++)
      {
        int prev =  a[x][y];
        int curx=x, cury=y;

        int tmpcnt=0;
        while (true)
        {
          curx += dx[k]; 
          cury += dy[k];

          if( curx <0 || cury <0 || curx>= n || cury>=m ) break;

          if( a[curx][cury] > prev ) tmpcnt++;
          else tmpcnt--;

          if( tmpcnt > mxcnt[k] ) mxcnt[k] = tmpcnt;
          if( tmpcnt < mncnt[k] ) mncnt[k] = tmpcnt;
          prev = a[curx][cury];
        }
      }

      int realmn = 0, realmx= 0;
      for (int k=0; k<4; k++)
      {
        mncnt[k] = abs(mncnt[k]), mxcnt[k] = abs(mxcnt[k]);
        realmn = max(mncnt[k], realmn);
        realmx = max(mxcnt[k], realmx);
      }
      printf("%d ", realmn+realmx+1);
    }
    printf("\n");
  }
}
