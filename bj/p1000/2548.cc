#include <stdio.h>
#include <algorithm>

using namespace std;

int a[(int)2e4];
int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  sort(a, a+n);

  if ( n%2 == 0 )  printf("%d\n", a[n/2-1]);
  else printf("%d\n", a[n/2]);
}

