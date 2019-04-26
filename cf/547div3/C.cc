#include <stdio.h>
#include <algorithm>

using namespace std;
int a[(int)2e5+1], diff[(int)2e5+1], presum[(int)2e5+1];
bool hit[(int)2e5+1];
int main()
{
  int n;
  scanf("%d",&n);
  for (int i=1; i<n; i++) scanf("%d", &diff[i]);

  int mx=0, mn = 0;

  for (int i=1; i<n; i++)
  {
    presum[i] = diff[i] + presum[i-1];
    mx = max(mx, presum[i]);
    mn = min(mn, presum[i]);
  }

  if (mx-mn != (n-1) ) 
  {
    return !printf("-1\n");
  }

  int realdiff = n - mx;
  a[1] = realdiff;
  hit[a[1]]=true;
  for (int i=1; i<n; i++)
  {
    presum[i] += realdiff;
    a[i+1] = presum[i];

    if (a[i+1] <1 || a[i+1] >n || hit[a[i+1]] ) return !printf("-1\n");

    hit[a[i+1]] = true;
  }

  for (int i=1; i<=n; i++) printf("%d ", a[i]);
  printf("\n");
}
