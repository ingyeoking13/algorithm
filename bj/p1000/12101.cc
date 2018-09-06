#include <stdio.h>

int n, k;
int cnt;
char s[12];

int dfs(int now, int idx)
{

  if (now== n)
  {
    cnt++;
    if ( cnt == k ) return 1;
    return 0;
  }

  if ( now > n) return 0;

  for (int i=1; i<=3; i++)
  {
    s[idx]=i;
    if(dfs(now+i, idx+1)) return 1;
    s[idx]=0;
  }
  return 0;

}

int main()
{
  scanf("%d %d", &n, &k);

  dfs(0, 0);

  if ( cnt== k) 
  {
    for (int i=0; s[i]; i++)
    {
      printf("%c", s[i]+'0');
      if(s[i+1]) printf("+");
    }
    printf("\n");
  }
  else printf("-1\n");
}
