#include <iostream>
#include <algorithm>

using namespace std;
int cnt[10];
int main()
{
  int n;
  cin >> n;

  char s[101];
  cin >> s;

  for (int i=0; i<n; i++) cnt[s[i]-'0']++;

  n /= 11;
  cout << min ( n, cnt[8]);
}
