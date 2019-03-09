#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
  int n;
  scanf("%d", &n);
  vector<int> a(n);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());

  long long ans =0;
  for (int i=0; i<n/2; i++)
  {
    ans += (a[i] +a[n-1-i])*(a[i]+a[n-1-i]);
  }
  printf("%lld\n", ans);
}
