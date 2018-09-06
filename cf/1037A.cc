#include <stdio.h>

int main()
{
  int ans=0;
  int n;
  scanf("%d", &n);

  while(n)
  {
    n/=2;
    ans++;
  }
  printf("%d\n", ans);

}
