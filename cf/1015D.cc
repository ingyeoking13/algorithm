#include <stdio.h>

void move(long long need, int pos, int n)
{
  if (pos+need < n)
  {
    printf("%d ", pos+need);

  }
  else 
  {

  }

}

int main()
{
  long long n, k, m;
  scanf("%lld %lld %lld", &n, &k, &m);

  if ( (n-1)*k < m) return !printf("NO\n");

  printf("YES\n");

  int pos =1;
  long long sum=0;

  for (int i=0; i<k; i++)
  {
    int need = (m-sum)/(k-i);
    move(need, pos, n);
  }

}
