#include <iostream>

using namespace std;
int a[(int)2e5];

int main()
{
  int tt=0;
  int T;

  cin >> T;
  while ( ++tt <= T)
  {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=1; i<n; i++)
    {
      if ( a[i] + a[i-1] > a[i] ) a[i] += a[i-1]; 
    }
    int ans = a[0];
    for (int i=1; i<n; i++)
    {
      if ( a[i] > ans ) ans = a[i];
    }

    cout << "#" << tt << " " << ans << "\n";
  }

}
