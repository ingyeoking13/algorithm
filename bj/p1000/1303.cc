#include <stdio.h>
char s[100][101];
char v[100][100];
int row, col;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
char st[2] = {'B', 'W'};

int dfs(int x, int y, char myst)
{
  int ret=1;
  v[x][y]=1;
  for (int i=0; i<4; i++)
  {
    int nx = x+dx[i], ny = y+dy[i];
    if ( 0 <= nx && nx< row && 0 <= ny && ny < col)
    {
      if (v[nx][ny] ==0 && s[nx][ny] == st[myst] )
      {
        ret += dfs(nx, ny, myst);
      }
    }
  }
  return ret;
}

int main()
{
  scanf("%d%d", &col, &row);
  for (int i=0; i<row; i++)
  {
    scanf("%s", s[i]);
  }

  int ansW=0, ansB=0;

  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      if (v[i][j] == 0) 
      {
        int tmp = dfs(i,j, s[i][j]=='W');
        if (s[i][j] == 'W') ansW += tmp*tmp;
        else ansB += tmp*tmp;
      }
    }
  }
  printf("%d %d\n", ansW, ansB);

}
