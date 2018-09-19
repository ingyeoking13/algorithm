#include <stdio.h>
#include <string.h>

char s1[151], s2[151], s3[301];
char ans[300];
int d[150][150];
int len;

int dfs(int i, int j, int k)
{
  if (d[i][j]==1) return 0;
  d[i][j] =1;
  if ( k==len)
  {
    for (int l=0; l<k; l++)
    {
      printf("%c", ans[l]+'0');
    }
    printf("\n");

    return 1;
  }

  if (s1[i] == s3[k]) 
  {
    ans[k]=1;
    if(dfs(i+1, j, k+1)) return 1;
  }
  if (s2[j] == s3[k])
  {
    ans[k]=2;
    if( dfs(i, j+1, k+1)) return 1;
  }
  return 0;

}

int main()
{
  scanf("%s%s%s", s1, s2, s3);
  len = strlen(s3);
  dfs(0, 0, 0);
}
