#include <stdio.h>

int a[(int)1e5];

int lessorsame, more;
int main()
{

  int n, power, repair;
  scanf("%d%d%d", &n, &power, &repair);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);

    if ( a[i] <= power) lessorsame++;
    else more++;
  }

  if (power > repair) 
  {
    printf("%d\n", n);
    return 0;
  }

  int mnbroken = lessorsame?1:0;
  printf("%d\n", mnbroken+(lessorsame-mnbroken)/2);

}
