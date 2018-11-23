#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool myfunc(pair<int, int> a, pair<int, int> b)
{
  return a.first < b.first;
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  vector<pair<int, int> >  v;
  while(m--)
  {
    int u, vv;
    scanf("%d %d", &u, &vv);
    v.push_back({u, vv});
  }
  sort(v.begin(), v.end(), myfunc);

  int cur=0, ans=0;
  for (auto e : v)
  {
    if (e.first > cur) 
    {
      ans += (e.first-cur);
    }

    if (e.second > cur)
    {
      cur = e.second;
    }
  }
  ans += (n-cur);
  printf("%d\n", ans);

}
