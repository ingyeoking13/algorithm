#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
  int a[50];
  int n, s, p;
  scanf("%d %d %d", &n, &s, &p);
  for (int i=0; i<n; i++) scanf("%d", &a[i]);

  sort(a, a+n);

  int ans=1;
  for (int i= n-1; i>=0; i--) if ( a[i] >= s) ans++;
  if ( ans > p) return !printf("-1\n");

  for (int i= n-ans+1; i<n; i++) if (a[i] <= s) ans--;
  printf("%d\n",ans);

}
