#include <stdio.h>
#include <string.h>

int abs(int x) {return x>0?x:-x;};
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  short board[2000][2000];
  for (int i=0; i<n; i++)
  {
    char s[3];
    char s2[2005];
    scanf("%s%s", s, s2);

    int num[2005];

    for (int j=0; j<m; j++)
    {
      if (s2[j] == '0') num[j]=0;
      else if (s[0] == 'L') num[j]=-1;
      else num[j]=1;
    }

    board[i][0] = num[0];
    for (int j=1; j<m; j++) board[i][j] = board[i][j-1] + num[j];
  }

  int col[2000];
  memset(col, 0, sizeof(col));

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      col[j] += board[i][j];
    }
  }

  int mn=1e9, ans=1;

  for (int i=0; i<n; i++)
  {
    int mx= 0;
    for (int j=0; j<m; j++)
    {
      if (abs(col[j]-board[i][j])>mx) mx=abs(col[j]-board[i][j]);
    }

    if (mn> mx) mn=mx, ans=i+1;
  }

  printf("%d\n%d\n", ans,mn); 
}
