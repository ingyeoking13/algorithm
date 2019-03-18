#include <stdio.h>

char s[5002], s2[5002];
int main()
{
  int n; scanf("%d", &n);
  scanf("%s", s);
  scanf("%s", s2);

  int a = 0, b=0, c=0, d =0;
  for (int i=0; i<n; i++)
  {
    char c1 = s[i], c2 = s2[i];
    if ( c1 == '0' &&  c2 == '0' ) a++;
    else if ( c1== '1' && c2 == '0' ) b++;
    else if ( c1== '1' && c2 == '1' ) d++;
    else c++;
  }

  for (int i=0; i<=a; i++)
  {
    for (int j=0; j<=d; j++)
    {
      if ( (j - i) == (- n/2 + c + d) )
      {
          char c1 = s[k], c2 = s2[k];
          /*
          if ( i>0 &&  c1 == '0' && c2=='0' ) 
          {
            i--; printf("%d ", k +1);
          }
          else if ( j >0 && c1 == '1' && c2 == '1' )
          {
            j--; printf("%d ", k +1);
          }
          */

        return 0;
      }
    }
  }

  printf("-1\n");
}
