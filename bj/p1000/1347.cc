#include <stdio.h>
#include <algorithm>

using namespace std;

char s[200][200];
char op[51];
int dx[4] = {0, -1, 0,1}, dy[4] ={-1, 0, 1, 0};

int main()
{

  int n;
  scanf("%d", &n);
  scanf("%s", op);

  int lx=100, ly=100, rx=100, ry= 100;
  int x = 100, y = 100;
  s[x][y] =1;

  int dir = 3; 
  for (int i=0; i<n; i++)
  {
    char c = op[i];
    if ( c== 'R')
    {
      dir++;
      dir%=4;
    }
    else if ( c == 'L')
    {
      dir--;
      if( dir <0) dir=3;
    }
    else x += dx[dir], y += dy[dir];

    s[x][y]=1;
    lx = min(lx, x);
    rx = max(rx, x);
    ly = min(ly, y);
    ry = max(ry, y);
  }

  for (int i=lx; i<=rx; i++)
  {
    for (int j=ly; j<=ry; j++)
    {
      if ( !s[i][j] ) printf("#");
      else printf(".");
    }
    printf("\n");
  }
}
