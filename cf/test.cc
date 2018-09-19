#include <stdio.h>

int gcd(int a, int b)
{
  return b?gcd(b, a%b):a;
}
int main()
{
  for (int i=3; i<=45000; i++)
  {
    int tmp=0, tmp1=0;
    for (int j=1; j<i; j++) tmp+=j;
    tmp1=i;
    printf("%d\n", i);
    if (gcd(tmp1, tmp) <=1) return 0; 
  }

}
