#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
  int n;
  cin >> n;
  int a[100];

  for (int i=0; i<n; i++) cin >> a[i];
  sort(a, a+n);
  int val = (a[0] +a[n-1]);
  if (val%2 == 1) 
  {
    bool chk= true;
    for (int i=0; i<n; i++)
    {
      if (a[i] == a[0] || a[n-1] == a[i] );
      else chk=false;
    }
    if (chk) cout << a[n-1]-a[0];
    else cout << -1;
    return 0;
  }

  val/=2;
  bool chk=true;
  int d = val -a[0];
  for (int i=1; i<n; i++)
  {
    int diff = a[i]-val;
    if (diff ==0) continue;
    if (diff <0) diff= -diff;
    if (diff != d) chk=false;
  }
  if (chk ) cout << d;
  else cout << -1;
}
