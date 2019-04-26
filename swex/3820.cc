#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

struct data
{
  long long a, b;
  data() {};
};

bool mycmp(const data &x, const data& y )
{
  if ( x.a == y.a ) return x.b < y.b;
  return x.a > y.a;
}

data a[(int)2e5];
int main()
{

  int T;
  int tt =0;
  cin >> T;
  while ( ++tt <= T)
  {
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
      cin >> a[i].a >> a[i].b;
    }
    sort(a, a+n, mycmp);

    long long ans = 1;
    for (int i=0; i<n; i++)
    {
      ans *= a[i].a;
      ans%=MOD;
      ans+= a[i].b;
      ans%=MOD;
    }

    cout << "#" << tt << " " << ans << "\n";

  }
}
