#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> a;
long long presum[(int)3e5];
bool mycomp(pair<int, int> x, pair<int, int> y) { return x.second > y.second; };

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  a.resize(n);

  for (int i=0; i<n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a.begin(), a.end(), mycomp);

  long long ans = 0, sum = 0;

  multiset<int> s;
  for (int i=0; i<n; i++)
  {
    s.insert(a[i].first);
    sum += a[i].first;

    if(s.size() > k )
    {
      auto it = s.begin();
      sum -=  *it;
      s.erase(it);
    }

    long long ret = sum*a[i].second;
    if (ret > ans ) ans = ret;
  }
  printf("%lld\n", ans);
}
