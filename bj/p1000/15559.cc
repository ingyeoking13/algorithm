#include <stdio.h>
#include <string.h>

char s[(int)1e3+1][(int)1e3+1];
int dx[4] = { 0, 0, 1, -1};
int dy[4] = { 1, -1, 0, 0};

bool v[(int)1e3+1][(int)1e3+1];
int curv[(int)1e3+1][(int)1e3+1];
int n, m;

bool go (int x, int y, int& col)
{
  if (curv[x][y] == col ) return true;
  if (v[x][y]) return false;

  curv[x][y] = col;
  v[x][y] =true;

  int nx = x+dx[s[x][y]], ny = y+dy[s[x][y]];

  if ( nx <0 || ny < 0 || nx>= n || ny >= m) return true;
  return go( nx, ny, col );
}

int main()
{
  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++) 
  {
    scanf("%s", s[i]);
    for (int j=0; j<m; j++)
    {
      char c = s[i][j];
      if ( c== 'N') s[i][j] =3;
      else if ( c== 'S' ) s[i][j] =2;
      else if ( c== 'E' ) s[i][j] = 0;
      else s[i][j] =1;
    }
  }
  memset(curv, -1, sizeof(curv));

  int ans =0;
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      int col = i*m+j;
      if( go( i, j, col )) ans++;
    }
  }
  printf("%d\n", ans);

}
