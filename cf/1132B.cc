#include <stdio.h> 
#include <algorithm>

using namespace std;
int a[(int)3e5+1];

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=1; i<=n; i++)
  {
    scanf("%d", &a[i]);
    a[i] = -a[i];
  }

  sort(a+1, a+n+1);
  for (int i=1; i<=n; i++) a[i] = -a[i];

  long long psum[(int)3e5+1];
  psum[0] = 0;
  for (int i=1; i<=n; i++) psum[i] = psum[i-1] + a[i];

  int m;
  scanf("%d", &m);

  while(m--)
  {
    int query;
    scanf("%d", &query);
    printf("%lld\n", psum[query-1] + psum[n]-psum[query]);
  }
}
