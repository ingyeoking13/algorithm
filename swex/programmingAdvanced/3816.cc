#include <iostream>
#include <string.h>

using namespace std;
char s1[(int)1e5+1], s2[(int)1e5+1];
int a[26], b[26];

int isSame()
{
  char ff = true;
  for (int i=0; i<26; i++)
  {
    if (a[i] != b[i] )  ff= false;
  }
  return ff;
}

int main()
{
  int T;
  int tt =0;
  cin >> T;
  while ( ++tt <= T )
  {
    cin >> s1 >> s2;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    int len = strlen(s1);
    int len2 = strlen(s2);

    int ans =0;
    for (int i=0; i<len ;i++) a[ s1[i]-'a' ]++;
    for (int i=0; i<len ;i++) b[ s2[i] - 'a' ]++;

    if (isSame()) ans++;

    for (int i=1; i+len-1<len2; i++)
    {
      b[ s2[i-1] -'a' ] --;
      b[ s2[i+len-1] -'a' ] ++;

      if (isSame()) ans++;
    }
    cout << "#" << tt << " " << ans << "\n";

  }
}
