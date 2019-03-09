#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int a[(int)2e5], b[(int)2e5];
map <string, int> cnt;
int gcd(int a, int b) { return b?gcd(b, a%b):a; };

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  for (int i=0; i<n; i++) scanf("%d", &b[i]);

  int spare = 0;
  for (int i=0; i<n; i++)
  {
    if (a[i] == 0 && b[i]!=0) continue;
    if (a[i] == 0 && b[i] == 0) 
    {
      spare++;
      continue;
    }
    if ( b[i] ==0) 
    {
      cnt["0"]++;
      continue;
    }

    int asign = 1;
    int bsign = 1;
    if ( a[i] < 0) a[i] = -a[i], asign =-1;
    if ( b[i] < 0) b[i] = -b[i], bsign =-1;

    int g= gcd(a[i], b[i]);
    string str;

    a[i] = a[i]/g, b[i] = b[i]/g;
    int sign = asign*bsign;

    if ( sign <0) str.push_back('-');

    while( a[i] )
    {
      str.push_back('0' + (a[i]%10));
      a[i]/=10;
    }
    str.push_back('/');

    while( b[i] )
    {
      str.push_back('0' + (b[i]%10));
      b[i]/=10;
    }
    cnt[str]++;
  }

  int ans=0;
  for (auto m: cnt)
  {
    //printf("%s\n", m.first.c_str());
    if (m.second > ans ) 
    {
      ans = m.second;
    }
  }
  printf("%d\n", ans+spare);
}
