#include <stdio.h>

char ans[1000];
int top=-1;

int main()
{
  long long n;
  scanf("%lld", &n);
  if (n==0) return !printf("0\n");

  while(n)
  {
    ans[++top] = (n%2)+'0';
    n/=2;
  }

  for (int i=top; i>=0; i--)
  {
    printf("%c", ans[i]);
  }

  printf("\n");
}
