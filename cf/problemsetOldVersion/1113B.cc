#include <stdio.h>
#include <algorithm>

using namespace std;
int main()
{

  int n;
  scanf("%d", &n);
  int a[(int)(5*1e4)];

  int sum=0;
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sort(a, a+n);

  int ans = sum;
  for (int i=1; i<n; i++)
  {

    for (int j=2; j<a[i]; j++)
    {

      if ( a[i]%j == 0 )
      {
        int tmp = sum;
        tmp -= a[0];
        tmp -= a[i];
        tmp += (a[i]/j);
        tmp += (a[0]*j);
        if ( tmp < ans ) ans = tmp;
      }
    }
  }

  printf("%d\n", ans);

}
