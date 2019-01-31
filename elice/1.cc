#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > a;
int main()
{
  int n, m, b;
  cin >> n >> m >> b;

  a.resize(m+1);
  a[0].first = 0;
  a[0].second=1e9;

  for (int i=1; i<=m; i++) cin >> a[i].first;
  for (int i=1; i<=m; i++) cin >> a[i].second;

  sort(a.begin(), a.end());

  int ans=0;
  int cnt=n;

  while (cnt >0 )
  {
    int mn = 1e9;
    int rep =-1, rep2 = -1;

    for (int i=0; i<=m; i++)
    {
      if (a[i].second <= 0) continue;

      for (int j=i; j<=m; j++)
      {
        if (a[j].second <= 0) continue;
        if ( a[i].first + a[j].first < mn && a[i].first + a[j].first >= b)
        {
          mn= a[i].first +a[j].first;
          rep= i, rep2 = j;
          break;
        }
      }
    }

    if (rep>=0)// 존재하면 
    {
      int ccc = min(a[rep].second, a[rep2].second);
      int realccc = min(cnt, ccc);
      a[rep].second -= realccc, a[rep2].second -= realccc;
      ans += realccc* mn;
      cnt -= realccc;
    }
    else break;
  }

  if (cnt >0 ) cout << "IMPOSSIBLE\n";
  else cout << ans << "\n";

}
