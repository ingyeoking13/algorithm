#include <stdio.h>
#include <string.h>

char s[(int)1e4][501];
char v[(int)1e4][500];
char allv[(int)1e4][500];
int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};

char dfs(int x, int y, int row, int col)
{
  v[x][y]=1;
  if (y == col-1) return 1;

  for (int i=0; i<3; i++)
  {
    int nx = x+dx[i], ny = y+dy[i];

    if (0<=nx && nx < row )
    {
      if (s[nx][ny] == '.' && (!v[nx][ny]) && (!allv[nx][ny]))
      {
        if (dfs(nx, ny, row, col)) 
        {
          allv[nx][ny]=1;
          return 1;
        }
      }
    }
  }
  return 0;
}
int main()
{
  int row, col;
  scanf("%d %d", &row, &col);

  for (int i=0; i<row; i++)
  {
    scanf("%s", s[i]);
  }

  int ans=0;
  for (int i=0; i<row; i++)
  {
    memset(v, 0, sizeof(v));
    if (s[i][0] == '.')
    {
      if(dfs(i, 0, row, col)) ans++;
    }
  }
  printf("%d\n", ans);

}
