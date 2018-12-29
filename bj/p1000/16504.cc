#include <stdio.h>

int main()
{
  long long sum=0;
  int n;
  scanf("%d",&n);
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      int tmp;
      scanf("%d", &tmp);
      sum = sum + tmp;
    }
  }
  printf("%lld\n", sum);
}
