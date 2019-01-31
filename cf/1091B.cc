#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int, int> > v;
vector< pair<int, int> > vv;

bool myfunc(pair<int, int> x, pair<int, int> y)
{
  return x.first > y.first;
}

bool myfunc2(pair<int, int> x, pair<int, int> y)
{
  return x.second > y.second;
}

bool myfunc3(pair<int, int> x, pair<int, int> y)
{
  return x.second < y.second;
}
int main()
{
  int n;
  cin >> n;

  for (int i=0; i<n ;i++)
  {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }

  for (int i=0; i<n ;i++)
  {
    int x, y;
    cin >> x >> y;
    vv.push_back({x, y});
  }
  sort(v.begin(), v.end());
  sort(vv.begin(), vv.end(), myfunc);

  int ansx = v[0].first + vv[0].first;

  sort(v.begin(), v.end(), myfunc2);
  sort(vv.begin(), vv.end(), myfunc3);
  int ansy = v[0].second + vv[0].second;
  cout << ansx << " " << ansy << "\n";

}
