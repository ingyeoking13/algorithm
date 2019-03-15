#include <stdio.h>

int main()
{
  int n, s;
  scanf("%d%d", &n, &s);

  int ans=0;
  for (int i=n; i>=1 && s>0; i--)
  {
    ans += s/i;
    s= s%i;
  }
  printf("%d\n", ans);
}
