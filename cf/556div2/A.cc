#include <iostream>
#include <algorithm>

using namespace std;
int a[30], b[30];

int main()
{
  int n, m, r;
  cin >> n >> m >> r;

  for (int i=0; i<n; i++) cin  >> a[i];
  for (int i=0; i<m; i++) cin  >> b[i];

  sort(a, a+n );
  sort(b, b+m );

  if ( a[0] >= b[m-1] ) cout << r;
  else
  {
    int q = r/a[0];
    r = r%a[0];

    r += q*b[m-1];
    cout << r <<"\n";
  }
}
