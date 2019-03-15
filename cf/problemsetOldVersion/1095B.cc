#include <stdio.h>
#include <algorithm>

using namespace std;

int a[(int)1e5];
int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  sort(a, a+n);

  int ans = min(a[n-2]- a[0], a[n-1]-a[1]);
  printf("%d\n" ,ans);
}
