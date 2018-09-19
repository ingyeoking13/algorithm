#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int now =1;
  int ans = 0;
  while(1)
  {
    if (n>=now);
    else now=1;

    if ( n==0) break;
    n-=now;
    now++;
    ans++;
  }
  printf("%d\n", ans);

}
