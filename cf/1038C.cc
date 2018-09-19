#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
  int a[(int)1e5], b[(int)1e5];
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  for (int i=0; i<n; i++) scanf("%d", &b[i]);

  sort(a, a+n);
  sort(b, b+n);

  int i=n-1, j=n-1;
  long long sa=0, sb=0;

  char state=0;
  while( i>=0 || j>=0)
  {
    //a turn
    if (i<0 ) j--;
    else if (j<0 || a[i]>= b[j]) 
    {
      sa += a[i];
      i--;
    }
    else j--;

    //b turn
    if (j<0) i--;
    else if (i<0 || b[j]>= a[i]) 
    {
      sb+= b[j];
      j--;
    }
    else i--;
  }
  printf("%lld\n", sa-sb);

}
