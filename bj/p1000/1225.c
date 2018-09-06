#include <stdio.h>
#include <string.h>

char s1[10001], s2[10001];
int main()
{
  scanf("%s %s", s1, s2);
  int len1 = strlen(s1), len2= strlen(s2);

  long long ans=0;
  for (int i =0; i< len1; i++)
  {
    int n = s1[i]-'0';
    for (int j=0; j<len2; j++)
    {
      int m = s2[j]-'0';
      ans+= (long long)n*m;
    }
  }
  printf("%lld\n", ans);

}
