#include <iostream>

using namespace std;

int a[(int)1e6], b[(int)1e6];
int main()
{
  int T;
  int tt=0;
  cin >> T;
  while ( ++tt <= T )
  {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];

    int mx = 0;
    for (int i=1; i<n; i++)
    {
      int diff = a[i] - a[i-1];
      if ( diff < 0) diff = -diff;
      if ( diff > mx ) mx = diff;
    }

    int l = 0, r= 1e9; 
    //cout << mx << "\n";
    int ans =-1;
    while ( l <= r )
    {
      for (int i=0; i<n ;i++ ) b[i] = a[i];

      int mid = (l+r)/2;
      long long cost = 0;
      for (int i=1; i<n; i++)
      {
        int diff = b[i] - b[i-1];
        if( diff  < 0 ) diff = -diff;
        if ( diff > mid  ) 
        {
          cost += (diff - mid); 
          if ( b[i] > b[i-1] ) b[i] -= (diff - mid); 
          else b[i-1] -= (diff-mid);
        }
      }

      if ( cost <= m )
      {
        r = mid -1;
        ans = mid;
      }
      else l = mid+1;
    }
    cout << "#" << tt << " " << ans << "\n";
  }
}
