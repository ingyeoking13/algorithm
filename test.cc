#include <stdio.h>
#include <stdlib.h>

char chk[46];
void go (int now, int j)
{
  if ( now == 6)
  {
    for (int i=1; i<=45; i++)
    {
      if ( chk[i] ) printf("%d ", i);
    }
    printf("\n");
    return;
  }

  for (int i=j; i<=45; i++)
  {
    if (chk[i]) continue;
    chk[i] = true;
    go(now+1, i+1);
    chk[i] = false;
  }

}

int main()
{
  freopen("output.txt", "w", stdout);
  go(0, 1);
}

