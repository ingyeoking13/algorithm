#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);

  for (int test_case = 1; test_case<=T ; test_case ++)
  {
    int a[(int)1e4];
    int n, k;
    scanf("%d%d", &n,&k);

    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);

    double ans=0;
    for (int i=n-k; i<n; i++)
    {
      ans += a[i];
      ans/=2;
    }

    printf("#%d %lf\n", test_case, ans);

  }
}
