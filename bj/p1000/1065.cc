#include <stdio.h>
#include <algorithm>

using namespace std;

int a[(int)2e5];
int main()
{
  int n, k;
  scanf("%d %d", &n, &k);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  sort(a, a+n);
  int ans=0;

  while(a[n-1] != a[0])
  {

    int now = a[n-1];
    int tmp=0;

    int i;
    for (i=n-2; i>=0; i--)
    {
      if ( tmp + (n-i-1)*(now-a[i]) <=k) 
      {
        tmp += (n-i-1)*(now- a[i]);
        now= a[i];
      }
      else 
      {
        int height=0;
        while( tmp+(n-i-1)*(height) <= k)
        {
          height++;
        }
        height--;
        now-=height;
        break;
      }
    }

    for (int j=n-1; j>i; j--)
    {
      a[j] = now;
    }
    ans++;
  }
  printf("%d\n", ans);

}
