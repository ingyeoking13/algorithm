#include <stdio.h>
#include <string.h>

bool moeum(char c)
{
  if (c== 'a' || c=='e' || c=='i' || c=='o' || c=='u') return 1;
  return 0;
}

int main()
{
  char s[23];
  while(scanf("%s",s))
  {
    if (strcmp(s, "end") == 0) break;

    int len = strlen(s);
    char op1 = moeum(s[0]), op2=0, op3=0;

    char before= s[0];
    for (int i=1; i<len; i++)
    {
      op1 |= moeum(s[i]);

      if (before == s[i]) 
      {
        if (!(s[i]== 'e' || s[i]=='o')) op3=1;
      }
      before= s[i];

      if ( i>=2)
      {
        char st[3] = {0, 0, 0};
        int cnt=0;
        for (int j=i; j>i-3; j--)
        {
          st[cnt++] = moeum(s[j]);
        }
        op2 |= ((st[0] == st[1] ) && (st[1] == st[2]));
      }
    }

    printf("<%s> ",s );
    if ((!op1) || op2 || op3 ) printf("is not acceptable.\n");
    else printf("is acceptable.\n");
  }

}
