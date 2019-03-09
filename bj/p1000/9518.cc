#include <stdio.h>
#include <string.h>

char s[50][51];
int dx[8]= {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[8]= { -1, 0, 1, 1, -1, 0, 1, -1};

int main()
{
  int row, col;

  scanf("%d%d", &row,&col);

  for (int i=0; i<row; i++) scanf("%s", s[i]);

  int ans=0;
  int solx=-1 , soly=-1;
  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      if ( s[i][j] != '.' ) continue;

      int x = i, y = j;

      int cnt =0;
      for (int k=0; k<8; k++)
      {
        int nx = x+dx[k] , ny = y+dy[k];
        if ( nx < 0 || nx >= row || ny <0 || ny>=col ) continue;
        if ( s[nx][ny] == 'o') cnt++;
      }
      if ( cnt > ans )
      {
        ans = cnt;
        solx= x, soly = y;
      }
    }
  }

  if ( solx >= 0 && soly >= 0 ) s[solx][soly] ='o';
  int dp[50][50];
  memset(dp, 0, sizeof(dp));

  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      if ( s[i][j] == '.' ) continue;

      if ( j+1 <col  && s[i][j+1] == 'o' ) dp[i][j+1]++;
      if ( i+1 <row && s[i+1][j] == 'o' ) dp[i+1][j]++;
      if ( i+1 <row && j+1<col && s[i+1][j+1] == 'o') dp[i+1][j+1]++;
      if ( i-1 >=0 && j+1<col && s[i+1][j+1] == 'o') dp[i+1][j+1]++;
    }
  }

  ans =0;
  for (int i=0; i<row; i++) for (int j=0; j<col; j++) ans += dp[i][j];

  printf("%d\n" ,ans);
}
