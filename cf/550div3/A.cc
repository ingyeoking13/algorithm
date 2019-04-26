#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  while(n--)
  {
    char s[(int)1e2+5];
    scanf("%s", s);

    int len = strlen(s);
    bool hit[26];
    memset(hit, 0 , sizeof(hit));

    bool ans=true;
    int mn =26, mx=0;
    for (int i=0; i<len; i++)
    {
      
      if (hit[s[i]-'a'])  ans = false;
      hit[s[i]-'a']=1;

      mn = min (mn, s[i]-'a');
      mx = max (mx, s[i]-'a');
    }

    bool fine=true;
    for (int i=mn; i<mx; i++)
    {
      if ( hit[i] == 0 ) fine =false;
    } 

    if (ans && fine ) printf("Yes\n");
    else printf("No\n");
  }
}
