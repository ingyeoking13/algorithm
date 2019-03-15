#include <stdio.h>
#include <algorithm>

using namespace std;

int d[(int)3e3], a[(int)3e3];
int main()
{
  int n; 
  scanf("%d", &n);

  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  int truck, heli;
  scanf("%d%d", &truck, &heli);

  sort(a, a+n);

  for (int i=0; i<n; i++)
  {
    if ( i == 0) d[i] = a[i]*truck;
    else d[i] = d[i-1] + a[i]*truck;

    int cost = heli;
    for (int j=i; j>=0; j--)
    {
      cost += (a[(i+j+1)/2] - a[j])*truck;
      d[i] = min( d[i], (j>0?d[j-1]:0) + cost);
    }
  }

  printf("%d\n", d[n-1]);
}
