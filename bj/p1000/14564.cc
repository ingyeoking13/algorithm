#include <stdio.h>

int main()
{
  int n, m, a;
  scanf("%d%d%d", &n, &m, &a);

  int num;
  int now =a;

  while(true)
  {
    scanf("%d", &num);
    int diff = m/2+1 - num;

    while(diff!=0)
    {
      if (diff<0) { now++; diff++; }
      else { 
        now--; diff--; 
        if (now ==0) now=n;
      }
    };

    now = now%n;
    if (now == 0) now=n;
    if (num == m/2+1) 
    {
      printf("0\n");
      break;
    }

    printf("%d\n", now);
  }
}
