#include <stdio.h>

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

char s[10][11];
char ans[10][11];

int main()
{
  int row, col;
  scanf("%d%d", &row, &col);
  for (int i=0; i<row; i++) 
  {
    scanf("%s", s[i]);
  }

  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      int x = i, y= j;
      if (s[x][y] == '.') 
      {
        ans[x][y] = '.';
        continue;
      }

      int cnt=0;
      for (int k=0; k<4; k++)
      {
        int nx = x+dx[k], ny = y+dy[k];
        if (0<= nx && nx<row && 0 <= ny && ny <col)
        {
          if(s[nx][ny]=='.')  cnt++;
        }else cnt++;
      }

      if (cnt>=3) ans[x][y] ='.';
      else ans[x][y]='X';
    }
  }

  int minx =row, miny=col, maxx=0, maxy=0; 
  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      if (ans[i][j]=='X')
      {
        if (minx > i) minx=i;
        if (miny > j) miny=j;
        if (maxx < i) maxx=i;
        if (maxy < j) maxy=j;
      }
    }
  }

  for (int i=minx; i<=maxx; i++)
  {
    for (int j=miny; j<=maxy; j++)
    {
      printf("%c", ans[i][j]);
    }
    printf("\n");
  }


}
