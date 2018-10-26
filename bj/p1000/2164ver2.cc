#include <stdio.h>
#define MOD 500000

int a[(int)5e5];
int main()
{
  int n; scanf("%d", &n);
  int l=0, r=n-1;
  for (int i=1; i<=n; i++) a[i-1]=i;

  while(n>1)
  {
    a[(r+1)%MOD] = a[(l+1)%MOD];
    l = (l+2)%MOD;
    r = (r+1)%MOD;
//    for (int i=l; i<=r; i++) printf("%d ", a[i]);
 //   printf("\n");
    n--;
  }
  printf("%d\n", a[l]);

}
