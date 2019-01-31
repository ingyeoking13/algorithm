#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#define MOD 998244353

using namespace std;

int a[(int)2e5];
int d[(int)2e5];
map<int, int> m;

int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++) 
  {
    scanf("%d", &a[i]);
    m[a[i]] = i;
  }

  d[0]=1;
  int mx= m[a[0]];

  for (int i=1; i<n; i++)
  {
    d[i] = d[i-1];
    if ( mx >= i )
    {
      mx = max(mx, m[a[i]]);
      continue;
    }

    d[i]= (d[i-1]*2)%MOD;
    mx = max(mx, m[a[i]] );
  }

  printf("%d\n", d[n-1]);
}
