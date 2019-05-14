#include <iostream>
#include <string.h>
using namespace std;

char s[(int)2e5+1];
char s2[(int)2e5+1];

int cnt[52];
int main()
{
  cin >> s;
  cin >> s2;
  int len = strlen(s2);
  for (int i=0; i<len; i++)
  {
    if ( 'a'<= s2[i] &&  s2[i] <='z' ) cnt[s2[i]-'a']++;
    else cnt[s2[i]-'A' + 26 ]++;
  }

  len = strlen(s);
  int ans =0, ans2=0;
  for (int i=0; i< len; i++)
  {
    if ( 'a'<= s[i] &&  s[i] <='z' )
    {
      int idx = s[i]-'a';
      if ( cnt[idx]) 
      {
        cnt[idx]--;
        ans++;
      }
      else if (  cnt[idx + 26] )
      {
        cnt[idx+26]--;
        ans2++;
      }
    }
    else 
    {
      int idx = s[i]-'A'+26;
      if ( cnt[idx] )
      {
        cnt[idx]--;
        ans++;
      }
      else if ( cnt[idx-26])
      {
        cnt[idx-26]--;
        ans2++;
      }
    }
  }
  cout << ans << " " << ans2 << "\n";
}
