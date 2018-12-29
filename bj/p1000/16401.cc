#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  int a[(int)1e6+1];
  for (int i=0; i<m; i++)
  {
    scanf("%d", &a[i]);
    a[i]= -a[i];
  }

  sort(a, a+m);
  for (int i=0; i<m; i++)
  {
    a[i] = -a[i];
  }

  int l=1, r=a[0];
  while(l<=r)
  {
    int mid = (l+r)/2;

    int cnt=0;
    bool chk=0;
    for (int i=0; i<m; i++)
    {
      cnt += (a[i]/mid);
      if ( a[i]/mid == 0) break;
      if ( cnt >= n ) 
      {
        chk=1;
        break;
      }
    }
    if ( chk ) l = mid+1;
    else r = mid-1; 
  }
  printf("%d\n", l-1);
}
