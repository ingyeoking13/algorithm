#include <stdio.h>

long long calc(int n)
{
  long long ans[10];
  for (int i=0; i<10; i++) ans[i] = 0;
  int l =1;
  int r =n;
  int base = 1;

  while (l <=r )
  {
    while ( r%10 != 9 && l<=r )
    {
      int tmp = r;
      while(tmp)
      {
        ans[tmp%10] += base;
        tmp/=10;
      }
      r--;
    }

    if ( r< l ) break;

    while( l%10 != 0 && l<=r )
    {
      int tmp = l;
      while(tmp)
      {
        ans[tmp%10] += base;
        tmp/=10;
      }
      l++;
    }

    l/=10; r/=10;

    for (int i=0; i<10; i++)
    {
      ans[i] += (r-l+1)*base;
    }

    base*=10;
  }

  long long ret =0;
  for (int i=0; i<=9; i++)
  {
    ret += (ans[i]*i);
  }

  return ret;
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%lld\n", calc(m)- calc(n-1));
}
