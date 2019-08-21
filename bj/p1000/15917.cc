/*
백준 15917 
2의 승수 인지 체크합니다.
*/
#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    int n;
    scanf("%d", &n);

    bool ans = true;
    while(n > 1)
    {
      if (n%2) 
      {
        ans = false;
        break;
      }
      n/=2;
    }
    printf("%d\n", ans);
  }
}
