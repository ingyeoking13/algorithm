#include <stdio.h>
#include <math.h>

int main()
{
  int q;
  scanf("%d", &q);

  while(q--)
  {
    int a;
    scanf("%d", &a);

    int copied = a;
    int cnt=0;
    bool zero = false;

    while(copied)
    {
      if (copied%2==0) zero=true;
      copied/=2;
      cnt++;
    }

    if ( zero ) printf("%d\n", (1<<cnt)-1);
    else
    {
      copied = a;
      int mn = -1;
      int sq = sqrt(copied);

      if ( sq ==1 )
      {
        printf("1\n");
        continue;
      }

      for (int i=2; i<=sq; i++)
      {
        if ( copied%i == 0) 
        {
          copied /= i;
          if (mn == -1 ) mn = i;
          break;
        }
      }

      if ( mn == -1 ) printf("1\n");
      else printf("%d\n", a/mn);
    }
  }
}
