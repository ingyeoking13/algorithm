#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  int a[(int)1e5];
  long long sum=0;

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    sum+= (long long)a[i];
  }
  sort(a, a+n);

  long long ans=0;
  int h=0;

  for (int i=0; i<n; i++)
  {
    ans++;
    if ( h < a[i]) h++;
  }

  //for (; h<= a[n-1] -1; h++)
  {
    ans += (long long)(a[n-1]-1-h);
  }
  printf("%lld\n", sum - ans);

}
