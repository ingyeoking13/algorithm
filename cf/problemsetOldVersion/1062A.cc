#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  vector<int> a(n+2);
  for (int i=1; i<=n; i++)
  {
    scanf("%d",&a[i]);
  }
  a[n+1]=1001;

  int ans=0;
  for (int f=0; f<n; f++)
  {
    for (int t=f+2; t<=n+1; t++)
    {
      if (a[t]-a[f] == t-f)
      {
//        printf("%d %d\n", f, t);
        ans = max(t-f-1, ans);
 //       printf("%d\n", ans);
      }
    }
  }
  printf("%d\n", ans);
}
