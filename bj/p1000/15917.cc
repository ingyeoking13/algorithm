#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    int n;
    scanf("%d", &n);

    int hit =0;
    int ans = 1;
    while(n)
    {
      if (n%2) hit++;

      if (hit >1 ) 
      {
        ans=0;
        break;
      }
      n/=2;
    }
    printf("%d\n", ans);
  }

}
