#include <stdio.h>
#include <string.h>
#include <vector>
#define MAX 600000

using namespace std;

char b[10000][60];
int query[60][60];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  int cnt=0;
  int ans=0;
  for (int i=0; i<n; i++)
  {
    int len;
    char tmp[7];
    scanf("%d%s", &len, tmp);

    int dup = 60/len;

    for (int j=0; j<dup; j++)
    {
      for (int k=0; k<len; k++)
      {
        b[cnt][j*len+k] = tmp[k];
      }
    }
    cnt++;
  }

  while(m--)
  {
    int pos, dir;
    scanf("%d%d", &pos, &dir);

    pos+=MAX;
    dir+=MAX;

    query[pos%60][dir%60]++;
  }

  for (int i=0; i<60; i++)
  {
    for (int j=0; j<60; j++)
    {
      if ( query[i][j] == 0 ) continue;
      int pos = i, dir = j;
      pos += dir;
      pos %= 60;

      bool ok = true;
      for (int k=0; k<cnt; k++)
      {
        if ( b[k][pos]== '0' )
        {
          ok =false;
          break;
        }
        pos += dir;
        pos %= 60;
      }
      if ( ok ) ans += query[i][j];
    }
  }
  printf("%d\n", ans);
}
