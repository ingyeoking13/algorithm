#include <stdio.h>
#include <algorithm>

using namespace std;
int main()
{
  int a[4];
  for (int i=0; i<4; i++)
  {
    scanf("%d", &a[i]);
  }
  sort(a, a+4);
  int aa = a[3]-a[0];
  int bb = a[1]-aa;
  int cc = a[2]-aa;
  printf("%d %d %d\n", aa, bb, cc);
}
