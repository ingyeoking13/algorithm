#include <stdio.h>
#include <string.h>

int main()
{
  char s[100][4001];
  int n=0;
  while(fgets(s[n], sizeof(s[n]),stdin))
  {
    n++;
    if (s[n-1][0] == '0')
    {
      n--; 
      break;
    }
  }

  char WHERE[1001], WHO[1001], WHAT[1001];

  fgets(WHO, sizeof(WHO), stdin);
  fgets(WHERE, sizeof(WHERE), stdin);
  fgets(WHAT, sizeof(WHAT), stdin);

  int WHEREl = strlen(WHERE);
  int WHOl = strlen(WHO);
  int WHATl = strlen(WHAT);

  if (WHO[WHOl-1] == '\n') WHO[WHOl-1]=0, WHOl--;
  if (WHERE[WHEREl-1] == '\n') WHERE[WHEREl-1]=0, WHEREl--;
  if (WHAT[WHATl-1] == '\n') WHAT[WHATl-1]=0, WHATl--;

  for (int i=0; i<n; i++)
  {
    int len = strlen(s[i]);
    bool change=0;
    for (int j=0; j<len; j++)
    {
      if (j+4<len && s[i][j] == 'W' && s[i][j+1] == 'H' && s[i][j+2] == 'E' 
          && s[i][j+3] == 'R' && s[i][j+4] == 'E') 
      {
        char tmp[2001];
        strcpy(tmp, s[i]+j+5);
        strcpy(s[i]+j, WHERE);
        strcpy(s[i]+j+WHEREl, tmp);
        change=1;
      }
      if (j+2<len && s[i][j] == 'W' && s[i][j+1] == 'H' && s[i][j+2] == 'O' )
      {
        char tmp[2001];
        strcpy(tmp, s[i]+j+3);
        strcpy(s[i]+j, WHO);
        strcpy(s[i]+j+WHOl, tmp);
        change=1;
      }

      if (j+3<len && s[i][j] == 'W' && s[i][j+1] == 'H' && s[i][j+2] == 'A' && s[i][j+3] == 'T')
      {
        char tmp[2001];
        strcpy(tmp, s[i]+j+4);
        strcpy(s[i]+j, WHAT);
        strcpy(s[i]+j+WHATl, tmp);
        change=1;
      }
    }
    if (change==1) i--;
  }

  for (int i=0; i<n; i++)
  {
    printf("%s", s[i]);
  }
}
