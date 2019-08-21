#include <iostream>
#include <algorithm>

using namespace std;

int a[(int)1e5+14];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, x, y;
  cin >> n >> x >> y;

  for (int i=0; i<7; i++) a[i] = 1e9+1;
  for (int i=7; i<n+7; i++) cin >> a[i];
  for (int i=n+7; i<n+14; i++) a[i] = 1e9+1;

  int ans = 1e9+1;
  for (int i=7; i<n+7; i++)
  {
    int s = i;
    int mn = a[s];
    bool chk = true;
    for (int j = i-x; j <i; j++) 
    {
      if ( a[j] < mn ) chk= false;
    }
    for (int j = i+1; j<= i+y; j++)
    {
      if ( a[j] < mn ) chk =false;
    }

    if( chk ) 
    {
      ans = s;
      ans -= 7;
      ans++;
      break;
    }
  }
  cout << ans <<"\n";
}