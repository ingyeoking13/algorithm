#include <stdio.h>
#include <string.h>

char a[1501][1501][4];
int Acolpsum[1501][1501], Browpsum[1501][1501];

int row, col;
int d[1501][1501];
int max(int x, int y ) { return x>y?x:y;}

int go(int x, int y)
{
  if ( x > row || y > col ) return -1e9;
  if ( d[x][y] >= 0) return d[x][y];
  if ( x== row && y == col) return d[x][y] = 0;

  d[x][y] = go(x, y+1) + Browpsum[x-1][y+1];
  d[x][y] = max( go(x+1, y) + Acolpsum[x+1][y-1], d[x][y]);
  d[x][y] = max( go(x+1, y+1) + Acolpsum[x+1][y] + Browpsum[x][y+1], d[x][y]);
  return d[x][y];
};

int main()
{

  scanf("%d%d", &row, &col);

  for (int i=1; i <=row; i++)
  {
    for (int j=1; j<=col; j++)
    {
      scanf("%s", a[i][j]);
    }
  }

  for (int i=1; i<=row; i++)
  {
    for (int j=1; j<=col; j++)
    {
      Acolpsum[i][j] += Acolpsum[i][j-1];
      Browpsum[i][j] += Browpsum[i-1][j];

      int cur = 0, k =1;
      while ( a[i][j][k] )
      {
        cur *= 10;
        cur += (a[i][j][k]-'0');
        k++;
      }
      if ( a[i][j][0] == 'A' ) Acolpsum[i][j] += cur;
      else Browpsum[i][j] += cur;
    }
  }
  memset(d, -1, sizeof(d));
  int ans = go(1, 1);
  printf("%d\n" ,ans);
}
