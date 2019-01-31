#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int a[2][(int)1e4];
bool occupied[2][(int)1e4];
int d[2][(int)1e4][2];

int dr[4] = { 1, 0, 0 , 0};
int dc[4] = { 0, 1, -1, 0};

int go(int row, int col, int curChk, int &mxlen, int cnt, int &W)
{
  if ( row == 1 && col == mxlen) 
  {
    int ret =0;
    for (int j=0; j<2; j++)
    {
      for (int i=0; i<mxlen; i++)
      {
        if ( occupied[j][i] ) continue;
        ret++;
      }
    }
    return ret+cnt;
  }

  if ( row == 0 && col == mxlen) return go(1, 0, curChk, mxlen, cnt, W);
//  if ( d[row][col][curChk] >= 0) return d[row][col][curChk];

  d[row][col][curChk] = 0;
  int tmp;

  if ( curChk == 1) 
  {
    if ( occupied[row][col] ) return 0x7f7f7f7f;
    occupied[row][col] =1;

    for (int i=0; i<3; i++)
    {
      int nrow = row+dr[i], ncol = col+dc[i];

      nrow%=2; 
      ncol%=mxlen;

      if ( occupied[nrow][ncol] ) continue;
      if ( a[nrow][ncol] + a[row][col] > W ) continue;

      occupied[nrow][ncol]=1;

      if ( nrow != row && ncol != col+1 ) 
      {
        tmp = go(row, col+1, 0, mxlen, cnt+1, W); // <---  1
      }
      tmp = min(tmp, go(row, col+1, 1, mxlen, cnt+1, W)); // <--- 2

      occupied[nrow][ncol]=0;
    }
    tmp = min(tmp, go(row, col+1, 0, mxlen, cnt+1, W)); // <--- 1
    tmp = min(tmp, go(row, col+1, 1, mxlen, cnt+1, W)); // <--- 2

    occupied[row][col]=0;
  }
  else 
  {
    tmp = go(row, col+1, 0, mxlen, cnt, W ); // <--- 1
    tmp = min(tmp, go(row, col+1, 1, mxlen, cnt, W )); // <--- 2
  }
  return d[row][col][curChk] = tmp;
}

int main()
{

  int  T;
  scanf("%d", &T);

  while(T--)
  {
    int n, W;
    scanf("%d%d", &n, &W);
    dc[2] = n-1;

    for (int i=0; i<2; i++)
    {
      for (int j=0; j<n; j++)
      {
        scanf("%d", &a[i][j]);
      }
    }

    memset(d, -1, sizeof(d));

    int ans = go( 0, 0, 0, n, 0, W);
    ans = min(ans, go( 0, 0, 1, n, 0, W));
    printf("%d\n", ans);
  }
}
