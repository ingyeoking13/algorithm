#include <stdio.h>
#include <string.h>

char s[(int)2e5+5];
char s2[(int)2e5+5];
int main()
{
  int n;
  scanf("%d", &n);
  scanf("%s%s", s, s2);

  for (int i=n-1; i>=0; i--)
  {
    int diff = s2[i] - s[i];
    if ( diff < 0 ) diff+=26;

    if ( s[i] + diff/2 > 'z' ) 
    {
      s[i] -= 26;
      s[i] += diff/2;
      s[i-1]++;
    } 
    else s[i] += diff/2;
    printf("%c \n", s[i]);
  }

  printf("%s\n", s);

}
