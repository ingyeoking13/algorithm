#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<int, int> left;
map<int, int> right;

int main()
{
  int a[(int)2e5+1];
  int n, m; scanf("%d %d", &n, &m);
  int idx=-1;
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    if ( a[i] == m )
    {
      idx = i;
    }
  }

  left[0]=1;
  right[0]=1;
  int cnt=0;
  for (int i=idx-1; i>=0; i--)
  {
    if ( a[i]<m ) cnt--;
    else cnt++;

    left[cnt]++;
  }

  cnt=0;
  for (int i=idx+1; i<n; i++)
  {
    if ( a[i]<m ) cnt--;
    else cnt++;

    right[cnt]++;
  }

  vector<pair<int, int> > vLeft;
  vector<pair<int, int> > vRight;

  for (auto i : left )
  {
    vLeft.push_back({i.first, i.second});
  }
  for (auto i: right)
  {
    vRight.push_back({i.first, i.second});
  }

  sort(vLeft.begin(), vLeft.end());
  sort(vRight.begin(), vRight.end());
  
  int l = 0, r = vRight.size()-1;

  long long ans=0;
  while(l< vLeft.size() && r>=0)
  {
    int tmp = vLeft[l].first + vRight[r].first ;

    if (tmp == 0 || tmp == 1)
    {
      ans = ans + (long long)(vLeft[l].second)*(vRight[r].second);
      if (tmp == 0) l++;
      else r--;
    }
    else if (tmp < 0 ) l++;
    else if ( tmp > 0 ) r--;
  }
  printf("%lld\n", ans);
}
