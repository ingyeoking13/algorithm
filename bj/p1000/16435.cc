#include <stdio.h>
#include <algorithm>
using namespace std;
int a[(int)1e3];

int main()
{
  int n, len;
  scanf("%d%d", &n, &len);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  sort(a, a+n);

  for (int i=0; i<n; i++)
  {
    if (len >= a[i] ) len++;
    else break;
  }
  printf("%d\n", len);

}

