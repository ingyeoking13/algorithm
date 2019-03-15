#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int a[(int)2e3];
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  bool chk=1;
  for (int i=1; i<n; i++)
  {
    if (a[i] <= a[i-1] )
    {
      chk=0;
    }
  }
  if (chk) {
    printf("0\n");
    return 0;
  }

  printf("%d\n", n+1);
  int q=1;
  for (int i=n-1; i>=0; i--)
  {
    int now = a[i];
    int gap = i - a[i]%n;
    if (gap<0) { gap = n+gap; }

    for (int j=i; j>=0; j--)
    {
      a[j] += gap;
    }
    printf("%d %d %d\n", q, i+1, gap);
  }
  printf("2 %d %d\n", n, n);
}
