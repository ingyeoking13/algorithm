#include <iostream>

using namespace std;
int main()
{
  long long n , m , k , l;
  cin >> n >> m >> k >> l;

  if ( n < m)
  {
    cout << -1;
    return 0;
  }

  long long d = n/m;
  long long gifts = d*m;
  if ( gifts - k >= l )
  {
    long long ans = -1;
    long long ll = 1, rr =d;
    while ( ll <= rr)
    {
      long long mid = (ll+rr)/2;
      if ( mid * m - k >= l )
      {
        ans = mid;
        rr = mid-1;
      }
      else ll = mid+1;
    }
    cout << ans;
  }
  else 
  {
    cout << -1;
  }
}
