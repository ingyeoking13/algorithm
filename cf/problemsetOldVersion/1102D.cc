#include <stdio.h>
#include <string.h>

char s[(int)3e5+1];
int a[3];
int main()
{
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int len = strlen(s);

  for (int i=0; i<len; i++) a[s[i]-'0']++;

  if ( a[0] == a[1] && a[1] == a[2] )
  {
    printf("%s\n", s);
    return 0;
  }

  int im0 = n/3 - a[0];
  int im1 = n/3 - a[1];
  int im2 = n/3 - a[2];

  int i = len-1;
  while( i >= 0 && im0 < 0 )
  {
    if ( s[i] == '0' )
    {
      if (im2 > 0 )
      {
        s[i] = '2';
        im2--; im0++;
      }
      else if (im1 > 0)
      {
        s[i] = '1';
        im1--; im0++;
      }
      else break;
    }
    i--;
  }

  i=0;
  while ( i<= len-1 && im1 < 0 )
  {
    if ( s[i] == '1')
    {
      if ( im0 > 0)
      {
        s[i] = '0';
        im0--; im1++;
      }
      else break;
    }
    i++;
  }

  i=len-1;
  while ( i>= 0 && im1 < 0 )
  {
    if ( s[i] == '1')
    {
      if ( im2 > 0)
      {
        s[i] = '2';
        im2--; im1++;
      }
      else break;
    }
    i--;
  }

  i=0;
  while ( i<=len-1 && im2 < 0 )
  {
    if (s[i] == '2')
    {
      if (im0 > 0 )
      {
        s[i] ='0';
        im0--; im2++;
      }
      else if (im1 > 0 )
      {
        s[i] ='1';
        im1--; im2++;
      }
      else break;
    }
    i++;
  }
  printf("%s\n", s);
}
