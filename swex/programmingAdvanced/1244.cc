#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
  int tt=0;
  int T; scanf("%d", &T);

  while(++tt<=T)
  {
    char str[7]; int swap;
    scanf("%s %d", str, &swap);
    int len = strlen(str);

    char copied[7]; 
    strcpy(copied, str);
    sort(copied, copied+len);
    for (int i=0; i<len/2; i++)
    {
      char tmp = copied[i];
      copied[i] = copied[len-i-1];
      copied[len-i-1] = tmp;
    }

    int diff=0;
    for (int i=0; i<len; i++)
    {
      if ( copied[i] != str[i] ) diff++;
    }

    int hit[10];
    bool chk=false;
    memset(hit, 0, sizeof(hit));
    for (int i=0; i<len; i++) 
    {
      if( hit[ str[i]-'0' ] ) chk=true;
      hit[ str[i] -'0' ]++;
    }

    if ( swap >= diff/2 + diff%2 )
    {
      swap -= (diff/2 + diff%2);
      if (swap%2 == 0 || chk) printf("#%d %s\n", tt, copied);
      else 
      {
        char tmp = copied[len-1];
        copied[len-1] = copied[len-2];
        copied[len-2] = tmp;
        printf("#%d %s\n", tt, copied);
      }
      continue;
    }

    bool modified[7];
    memset(modified, 0, sizeof(modified));

    while( swap )
    {
      char mx=0; int idx = 7;
      for (int i=0; i<len; i++)
      {
        if ( mx <= str[i] && modified[i] == false ) 
        // choose a max elem which is not modified
        {
          mx = str[i];
          idx = i;
        }
      }

      int j=7;
      for (int i= idx-1; i>=0; i--)
      {
        if ( str[idx] > str[i] && modified[i] ==false ) j=i;
      }

      if( j==7 )  // case that position of a mx element is perfect position.
      {
        modified[idx]=true;
        continue;
      }

      char tmp = str[j];
      str[j] = str[idx];
      str[idx] = tmp;
      modified[j]=true;
      swap--;
    }

    printf("#%d %s\n", tt, str);
  }
}
