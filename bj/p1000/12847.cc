#include <iostream>

using namespace std;
long long a[(int)1e5];
long long b[(int)1e5];

int main()
{

  int n, m;
  cin >> n >> m;
  for (int i=0; i<n; i++) cin >> a[i];


  long long ans=a[0];

  for (int i=1; i<n; i++)
  {
    a[i] += a[i-1];
    if (ans < a[i] && i<m) ans = a[i];
  }

  for (int i=m; i<n; i++)
  {
    b[i] = a[i]-a[i-m];
    if ( ans < b[i] ) ans = b[i];
  }
  cout << ans << "\n";
}
