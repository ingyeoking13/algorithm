#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> v[123456];
bool wolf[123456];
int num[123456];

ll go(int cur)
{
  ll ret = 0;
  for (int i=0; i<v[cur].size(); i++)
  {
    int j = v[cur][i];
    ret += go(j);
  }
  if ( wolf[cur] ) ret = max( (ll)0, ret-num[cur]);
  else ret += num[cur];

  return ret;
}

int main()
{
  int n;
  cin >> n;
  for (int i=1; i<n; i++)
  {
    char st[2];
    int m, p;

    cin >> st >> m >> p;

    if (st[0] == 'W') wolf[i] = true;
    p--;

    num[i] += m;
    v[p].push_back(i);
  }
  cout<<  go(0);
}
