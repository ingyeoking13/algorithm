#include <stdio.h>
#include <string.h>

char s[33];
void ret (int &x, int &y, char c)
{
  if( c == '0' ) { x*= 2; y*= 2; }
  else if ( c == '1') { x*=2; y*=2; y+=1; }
  else if ( c== '2' ) { x*=2; y*=2; x+=1; }
  else { x*=2; y*=2; x++, y++; }
}
int main()
{
  scanf("%s", s);
  int len = strlen(s);
  printf("%d ", len);

  int x=0, y=0;

  for (int i=0; i<len; i++)
  {
    ret(x, y, s[i]);
  }
  printf("%d %d\n", y, x);
}
