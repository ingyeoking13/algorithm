#include <stdio.h>

char s[3][4];

bool func( char c )
{
  bool chk=false;
  for (int i=0; i<3; i++) 
  {
    if ( s[i][0] ==c )
    {
      bool thischk= true;

      for (int j=1; j<3; j++)
      {
        if ( s[i][j] != s[i][j-1] )
        {
          thischk=false;
        }
      }
      if (thischk) 
      {
        chk=true; 
        break;
      }
    }

    if ( s[0][i] == c )
    {

      bool thischk= true;

      for (int j=1; j<3; j++)
      {
        if ( s[j][i] != s[j-1][i] )
        {
          thischk=false;
        }
      }

      if (thischk) 
      {
        chk=true; 
        break;
      }
    }
  }

  if ( s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[2][2] == c) chk= true;
  if ( s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[2][0] == c) chk= true;
  return chk;

}
int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    for (int i=0; i<3; i++) scanf("%s", s[i]);

    int o =0, x=0;
    for (int i=0; i<3; i++)
    {
      for (int j=0; j<3; j++)
      {
        if ( s[i][j] == 'O' ) o++;
        else if ( s[i][j] =='X' ) x++;
      }
    }

    if ( o == x)
    {
      bool chk = func('X');
      if ( chk ) printf("no\n");
      else printf("yes\n");
    }
    else if ( o+1 == x )
    {
      bool chk = func('O');
      if ( chk ) printf("no\n");
      else printf("yes\n");
    }
    else printf("no\n");
  }
}
