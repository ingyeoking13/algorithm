#include <stdio.h>


int a[(int)1e5], b[(int)1e5];
int main()
{
  int n;
  scanf("%d", &n);

  int asum = 0, bsum=0;
  for (int i=0; i<n; i++)
  {
    scanf("%d%d", &a[i], &b[i]);
    asum+= a[i], bsum+=b[i];
  }


}
