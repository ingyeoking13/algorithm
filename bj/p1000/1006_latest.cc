#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[2][(int)1e4];
bool visited[2][(int)1e4];
int d[2][(int)1e4][2][2];

int mxcol;
int mxlen;

int dr[3] = { 1, 0, 0};
int dc[3] = { 0, 1, -1};

int go(int row, int col, int curChk, int cnt, int &W)
{
  if (visited[row][col])  {
    return mxlen;
  }
  if (cnt == mxlen) {
    return curChk==0?1:0;
  }

  d[row][col][curChk][1] = d[row][col][curChk][0]= 0;
  int tmp;

  if (curChk == 1) 
  {
    if ( visited[row][col] ) return 0x7f7f7f7f;
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
        tmp = go(row, col+1, 0,  cnt+1, W); // <---  1
      }
      tmp = min(tmp, go(row, col+1, 1,  cnt+1, W)); // <--- 2

      occupied[nrow][ncol]=0;
    }
    tmp = min(tmp, go(row, col+1, 0, cnt+1, W)); // <--- 1
    tmp = min(tmp, go(row, col+1, 1, cnt+1, W)); // <--- 2

    occupied[row][col]=0;
  }
  else 
  {
    tmp = go(row, col+1, 0, cnt, W ); // <--- 1
    tmp = min(tmp, go(row, col+1, 1, cnt, W )); // <--- 2
  }
  return d[row][col][curChk] = tmp;
}

int main()
{

  int T;
  cin >> T;

  while(T--)
  {
    int n, w;
    cin >> n >> w;

    mxcol = n;
    mxlen = 2*n;

    for (int i=0; i<2; i++)
    {
      for (int j=0; j<n; j++)
      {
        cin >> a[i][j];
      }
    }

    memset(d, 0, sizeof(visited));
    memset(d, -1, sizeof(d));
    go(1, n, 1, 0, w);
    cout << max(d[1][n][1][0], d[1][n-1][1][1]) << "\n";
  }
}
