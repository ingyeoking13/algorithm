#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;
char s[1000][1003];
int d[1000][1000];
bool inQ[1000][1000];
int main()
{
  int row, col;
  cin >> row >> col;

  int sx=-1, sy=-1;
  for (int i=0; i<row; i++)
  {
    cin >> s[i];
    for (int j=0; j<col; j++)
    {
      if ( s[i][j] == 'R' )
      {
        sx = i, sy = j;
      }
    }
  }
  memset(d, -1, sizeof(d));
  d[sx][sy] = 0;
  queue<pair<int, int>> q;
  q.push({sx, sy});
  while (!q.empty())
  {
    auto now = q.front();
    q.pop();

    int x = now.first;
    int y = now.second;
    inQ[x][y] =false;

    for (int i=-1; i<=1; i++)
    {
      int nx = x+i, ny = y+1;
      if (nx < 0 || nx >= row ) continue;
      if (ny >= col ) continue;

      if (s[nx][ny] == '#') continue;

      if ( d[nx][ny] < d[x][y] + (s[nx][ny]=='C'?1:0))
      {
        d[nx][ny] = d[x][y] +(s[nx][ny]=='C'?1:0);
        if (! inQ[nx][ny] ) q.push({nx,ny});
        inQ[nx][ny] = true;
      }
    }
  }

  /*

  for (int i=1; i<col; i++)
  {
    for (int j=0; j<row; j++)
    {

      int x = j, y = i;
      if (s[x][y] == '#') continue;
      for (int k=-1; k<=1; k++)
      {
        if ( x+k >= row || x+k < 0 ) continue;

        d[x][y] = max( d[x][y], d[x+k][y-1] + (s[j][i]=='C'?1:0) );
      }
    }
  }
  */

  int ans = -1;
  for (int i=0; i<row; i++)
  {
    for (int j=0 ; j<col; j++)
    {
      if ( s[i][j] != 'O' ) continue;
      if ( d[i][j] > ans ) ans = d[i][j];
    }
  }
  cout << ans <<"\n";
}
