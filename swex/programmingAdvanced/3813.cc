#include <iostream>
using namespace std;

int a[(int)2e5], b[(int)2e5];
int c[(int)2e5];
int main()
{

  int tt =0;
  int T;
  cin >> T;
  while ( ++ tt <= T )
  {
    int n, k;
    cin >> n >> k;

    int mn =2e9;
    for (int i=0; i<n; i++) 
    {
      cin >> a[i];
      if ( mn > a[i] ) mn = a[i];
    }
    for (int i=0; i<k; i++) cin >> b[i];

    int l = mn, r=(int) 2e5;  
    int ans =-1;
    while ( l<= r)
    {
      int mid = (l+r)/2;
      int idx = 0;

      bool possible = true;
      for (int i=0; i<k; i++)
      {
        bool chk= false;
        int cnt =0; 

        for (int j=idx; j<n; j++)
        {
          if ( a[j] <= mid ) cnt++;
          else cnt=0;

          if ( cnt == b[i] )
          {
            chk = true;
            idx = j+1;
            break;
          }
        }

        if (!chk )
        {
          possible = false;
          break;
        }
      }

      if (possible)
      {
        r = mid -1;
        ans = mid;
      }
      else l = mid+1;
    }
    cout << "#" << tt << " " << ans << "\n";
  }
}
