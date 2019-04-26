#include <stdio.h>

char s[65002];

int main()
{
  long long ans=0;

  int n;
  scanf("%d", &n);
  scanf("%s", s);

  for (int i=0; i<n; i++)
  {
    if ( (s[i]-'0')%2 == 0 )
    {
      ans += (i+1);
    }
  }
  printf("%lld\n", ans);
}
