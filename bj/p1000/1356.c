#include <stdio.h>
#include <string.h>
char s[100];

int myfunc(int f, int t)
{
  int ret =1;

  for (int i=f; i<=t; i++)
  {
    ret *= (s[i]-'0');
  }
  return ret;

}

int main()
{
  scanf("%s", s);
  int len = strlen(s);

  int chk=0;
  for (int i=0; i<=len-2; i++)
  {
    if ( myfunc(0, i) == myfunc(i+1, len-1))
    {
      printf("YES\n");
      chk=1;
      break;
    }

  }
  if (chk==0) printf("NO\n");
}
