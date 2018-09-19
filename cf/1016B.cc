#include <stdio.h>

char ans[1000];
char s[1001], t[1001];
int main()
{
  int lenS, lenT, q;
  scanf("%d %d %d", &lenS, &lenT, &q);

  scanf("%s %s", s, t);

  for (int i=0; i<lenS; i++)
  {
    int chk=1;
    for (int j=0; j<lenT; j++)
    {
      if (i+j >=lenS) 
      {
        chk=0;
        break;
      }
      if (s[i+j] != t[j]) 
      {
        chk=0;
        break;
      }
    }

    if (chk) ans[i]=1;
  }

  while(q--)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    int cnt=0;
    for (int i=x; i<=y; i++)
    {
      if( ans[i] && i+lenT-1<=y )  cnt++;
    }
    printf("%d\n", cnt);
  }
}
