#include <stdio.h>

bool a[100][100];
int max(int x, int y) { return x>y?x:y; };
int main()
{
  int row, col;
  scanf("%d%d", &col, &row);
  int Q;
  scanf("%d", &Q);

  while(Q--)
  {
    int dir, num;
    scanf("%d%d", &dir, &num);
    num--;

    if ( dir )  for (int i=0; i<row; i++) a[i][num]=1;
    else for (int i=0; i<col; i++) a[num][i]=1;
  }


  int mx=0;
  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      int x= i, y = j;
      
      int xlen = 1;
      int ylen = 1;
      while( x+xlen <row && !a[x+xlen-1][y] ) xlen++;
      while( y+ylen < col && !a[x][y+ylen-1] ) ylen++;
      mx = max( mx,xlen*ylen);
    }
  }
  printf("%d\n", mx);
}
