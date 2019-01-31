#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>

using namespace std;

int a[(int)1e5];
long long d[4][(int)1e5+1];
string s;
string hard = "hard";

long long go(int state, int i)
{
  if ( i == s.size() ) return 0;

  if ( d[state][i] >= 0) return d[state][i];

  d[state][i]=0;

  if ( s[i] != hard[state] ) 
  {
    return d[state][i]= go(state, i+1);
  }
  else
  {
    if ( state == 3) return d[state][i] = go(state, i+1) + a[i];
    else return d[state][i] = min( go(state+1, i+1), go(state, i+1)+a[i]);
  }
}
int main()
{
  int n;
  cin >> n;
  cin >> s;

  memset(d, -1, sizeof(d));
  for (int i=0; i <n; i++) cin >> a[i];
  cout << go(0, 0) << "\n";
}
