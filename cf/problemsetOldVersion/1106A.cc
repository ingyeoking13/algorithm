#include <stdio.h>

char s[500][505]; 

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    scanf("%s", s[i]);
  }

  int ans=0;
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      if ( i -1 < 0 || i +1 >= n || j-1 < 0 || j+1 >= n ) continue;


      if ( s[i][j] =='X' && s[i-1][j-1] == 'X' && 
           s[i+1][j-1] == 'X' && s[i+1][j+1] == 'X' && 
           s[i-1][j+1]=='X' )  ans++;
    }
  }
  printf("%d\n", ans);
}
