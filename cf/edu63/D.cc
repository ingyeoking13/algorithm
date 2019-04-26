#include <iostream>
#include <algorithm>
using namespace std;

long long mxd[(int)3e5];

long long mnd[(int)3e5];
int mnl[(int)3e5], mnr[(int)3e5];
long long a[(int)3e5];

int main()
{
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  for (int i=0; i<n; i++) cin >> a[i];

  mxd[0] = mnd[0] = a[0];

  for (int i=1; i<n; i++)
  {
    if ( a[i] + mxd[i-1] < a[i] ) mxd[i] = a[i];
    else mxd[i] = a[i]+mxd[i-1];

    if (a[i] + mnd[i-1] >=a[i] ) 
    {
      mnd[i] =a[i];
      mnl[i] = mnr[i] = i;
    }
    else 
    {
      mnd[i] = a[i]+mnd[i-1];
      mnl[i] = mnl[i-1];
      mnr[i] = i;
    }
  }

  long long mx =mxd[0];
  for (int i=1; i<n; i++) mx =  max(mx, mxd[i]);

  if ( m >= 0 ) 
  {
    if ( mx < 0 ) mx = 0;
    cout << mx*m << "\n";
  }
  else // m is negative
  {
    long long mn = mnd[0];
    long long mnll =mnl[0], mnrr = mnr[0];
    for (int i=1; i<n; i++) 
    {
      if ( mn > mnd[i] )
      {
        mn = mnd[i];
        mnll = mnl[i];
        mnrr = mnr[i];
      }
    }
    //cout << mnll << " " << mnrr << "\n";

    if (mn < 0 )
    {
      for (int i =mnll; i<=mnrr; i++) a[i]*=m;
      long long ans=0;

      mxd[0] = a[0];
      /*
      for( int i =0; i< n;  i++ ) cout <<  a[i] << " "  ;
      cout << "\n";
      */
      for (int i=1; i<n; i++)
      {
        if ( a[i] + mxd[i-1] < a[i] ) mxd[i]=a[i];
        else mxd[i] = mxd[i-1] +a[i];
        ans = max(mxd[i], ans);
      }
      //cout << mx <<  " " << ans << "\n";
      ans = max (ans, mx);
      cout << max(ans, 0LL) << "\n";
    }
    else 
    {
      if ( mx < 0) mx = 0;
      cout << mx << "\n";
    }
  }
}
