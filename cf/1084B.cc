#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long lev(long long a) { return a>0?a:0; };
int main()
{
  int n;
  long long s;

  cin >> n;
  cin >> s;
  vector<int> v(n);

  long long r=0;
  long long mn =1e9+1;
  for (int i=0; i<n; i++)
  {
    cin >> v[i];

    if ( r < v[i]) r=v[i];
    if ( mn > v[i]) mn =v[i];
  }

  long long l=0;


  while(l<=r)
  {
    long long mid = (l+r)/2;

    long long tmp=0;
    for (int i=0; i<n; i++)
    {
      tmp = tmp + lev(v[i]-mid);
    }

    if (tmp >= s) l=mid+1;
    else r =mid-1; 
  }

  long long sum=0;
  for (int i=0; i<n; i++)
  {
    sum = sum + lev(v[i]-l);
  }

  if (sum >= s) cout << min(l,mn) << "\n";
  else if(l-1>=0) cout << min(l-1,mn) << "\n";
  else cout << -1 << "\n";

}
