#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long a[(int)3e5], b[(int)3e5];
vector<long long> v;

long long gcd (long long a, long long b )
{
  return b?gcd(b, a%b):a;
}

int main()
{
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<m; i++) cin >> b[i]; 

  for (int i=1; i<n; i++)
  {
    v.push_back(a[i] - a[i-1]);
  }

  long long g = v[0];
  for (int i=1; i<v.size(); i++) g= gcd(g, v[i]);

  for (int i=0; i<m; i++)
  {
    if ( g%b[i] == 0)
    {
      cout << "YES\n";
      cout << a[0] << " " << i+1 << "\n";
      return 0;
    }
  }
  cout << "NO\n";
}
