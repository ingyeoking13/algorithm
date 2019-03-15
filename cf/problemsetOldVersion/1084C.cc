#include <stdio.h>
#include <string.h>
#include <vector>

#define MOD (int)(1e9+7)

using namespace std;

int main()
{
  char s[(int)1e5+5];
  scanf("%s", s); 
  int len = strlen(s);
  vector<int> v;

  int cnt=0;

  int tmp=0;
  for (int i=0; i<len; i++)
  {
    if (s[i] == 'a') cnt++, tmp++;
    else if (s[i] == 'b') 
    {
      if (tmp ) v.push_back(tmp), tmp=0;
    }
  }
  if (tmp) v.push_back(tmp);

  long long ans = 1;
  for (int i=0; i<v.size(); i++)
  {
    ans = ans*(v[i]+1);
    ans %= MOD;
  }
  ans--;
  printf("%lld\n", ans);
}
