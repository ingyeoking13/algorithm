#include <stdio.h>

int gcd(int a, int b)
{
  return b?gcd(b,a%b):a;
}

int main()
{
  int n;
  scanf("%d", &n);

  if (n <=2 ) return !printf("No\n");
  else
  {
    printf("Yes\n");
    int cnt=0;
    for (int i=1; i<=n; i++) if (i%2) cnt++;
    printf("%d ", cnt);
    for (int i=1; i<=n; i++) if (i%2) printf("%d ", i);
    printf("\n");

    cnt=0;
    for (int i=1; i<=n; i++) if (i%2==0) cnt++;
    printf("%d ", cnt);
    for (int i=1; i<=n; i++) if (i%2==0) printf("%d ", i);
    printf("\n");
  }
}
