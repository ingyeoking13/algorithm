#include <stdio.h>
#include <algorithm>
using namespace std;
int a[3];
int main()
{
  for (int i=0; i<3; i++)
  {
    scanf("%d", &a[i]);
  }
  sort(a, a+3);
  int d1 = a[1] -a[0];
  int d2 = a[2] -a[1];
  int ans = min(d1, d2);
  if ( d1 == d2)
  {
    printf("%d\n", a[0]-d1);
  }
  else if (d2 > d1)
  {
    printf("%d\n", a[1]+d1);
  }
  else
  {
    printf("%d\n", a[1]-d2);
  }

}
