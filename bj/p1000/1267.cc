#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  int Y=0, M=0;
  for (int i=0; i<n; i++)
  {
    int time;
    scanf("%d", &time);
    if (time ==0) continue;

    int tmp= time;
    int cost =0;
    while (tmp >=0 )
    {
      tmp-=30;
      cost += 10;
    }
    Y += cost;

    cost=0;
    tmp = time;
    while(tmp>=0)
    {
      tmp-=60;
      cost += 15;
    }
    M += cost;
  }

  if ( Y== M) printf("Y M %d\n", Y);
  else if ( Y>M) printf("M %d\n", M);
  else printf("Y %d\n", Y);
}
