#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a>b?a:b; }
char ans[1002];
int d[1001][1001];
int main()
{
  char s[1002], s2[1002];
  scanf("%s %s",s+1, s2+1);

  int len = strlen(s+1);
  int len2= strlen(s2+1);

  for (int i=1;i<=len;i++)
  {
    for (int j=1; j<=len2; j++)
    {
      if ( s[i] == s2[j] )
      {
        d[i][j] = d[(i-1)][j-1]+1;
      }
      else
      {
        d[i][j] = d[(i-1)][j];

        if ( d[i][j] < d[i][j-1] ) 
        {
          d[i][j] = d[i][j-1];
        }
      }
    }
  }

  printf("%d\n", d[len][len2]);
  int i=len, j = len2;
  int anslen = d[len][len2];
  while( i>0 && j >0 )
  {

    if ( s[i] == s2[j] )
    {
      ans[anslen-1] = s[i];
      i--, j--;
      anslen--;
    }
    else if (d[i-1][j] > d[i][j-1] ) i--;
    else j--;
  }
  printf("%s\n", ans);

}
