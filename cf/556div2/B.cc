#include <iostream>
#include <string.h>

using namespace std;

char s[50][52];

int dx[4] ={-1, 1, 0, 0};
int dy[4] ={0, 0, -1, 1};

int n;

int main()
{
  cin >> n;

  for (int i=0; i<n; i++) cin >> s[i];

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {

      int x = i, y = j;
      if ( s[x][y] =='#' ) continue;

      bool chk =true;
      for (int k=0; k<4;  k++)
      {
        int nx =  x+dx[k], ny = y+dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) 
        {
          chk =false;
          continue;
        }
        if ( s[nx][ny] == '#' ) chk =false;
      }

      if ( chk ) 
      {

        for (int k=0; k<4;  k++)
        {
          int nx =  x+dx[k], ny = y+dy[k];
          s[nx][ny] ='#';
        }
        s[x][y] = '#';
      }
    }
  }

  bool ans =true;
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      if ( s[i][j] == '.' ) ans = false;
    }
  }
  if (ans ) cout << "YES\n";
  else cout << "NO\n";

}
