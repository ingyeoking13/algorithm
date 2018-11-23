#include <stdio.h>
#include <string.h>

int st[26];
int main()
{
  st['c'-'a'] = 0; st['r'-'a'] = 1;
  st['o'-'a'] = 2; st['a'-'a'] = 3; st['k'-'a'] = 4;

  int T;
  scanf("%d", &T);

  for (int tt=1; tt<=T; tt++)
  {
    char s[2502];
    scanf("%s", s);

    int len = strlen(s);

    int manst[500];
    memset(manst, 0, sizeof(manst));

    int ans=0;
    for (int i=0; i<len; i++)
    {

      char chk = 0;
      for (int j=0; j<ans; j++)
      {

        if (manst[j] == st[s[i]-'a'] )
        {
          manst[j]++;
          chk=1;
          if (manst[j]==5) manst[j]=0;
          break;
        }
      }

      if (!chk)
      {
        if ( s[i] != 'c') 
        {
          ans=0;
          break;
        }
        manst[ans++]=1;
      }
    }

    for (int i=0; i<ans; i++)
    {
      if (manst[i] !=0) ans=0;
    }

    if (ans == 0) ans = -1;
    printf("#%d %d\n", tt, ans);
  }

}
