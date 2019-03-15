#include <stdio.h>

int abs(int x ){ return x>0?x:-x;};
int main()
{

  while(1)
  {
    int a[4];
    for (int i=0; i<4; i++) scanf("%d", &a[i]);
    if ( (a[0] == a[1]) && (a[1] == a[2] ) && (a[2] ==a[3] ) && (a[3] == 0))
    {
      break;
    }

    int cnt =0;
    while ( 1 )
    {
      if ( (a[0] == a[1]) && (a[1] == a[2]) && (a[2] == a[3]) )
      {
        break;
      }
      int b[4];
      b[0] = abs(a[0]- a[1]);
      b[1] = abs(a[1]- a[2]);
      b[2] = abs(a[2]- a[3]);
      b[3] = abs(a[3]- a[0]);
      for (int i=0; i<4; i++) a[i] =b[i];
      cnt++;
    }
    printf("%d\n" ,cnt);
  }
}
