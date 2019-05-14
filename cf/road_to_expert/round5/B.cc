#include <iostream>
#include <algorithm>

using namespace std;

long long a[3];
int main()
{
  cin >> a[0] >> a[1] >> a[2];

  long long ans = (2e18)+1;
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      if ( i == j )
      {
        long long tmp =0;
        long long mx = 0;

        for (int k=0; k<3; k++ )
        {
          if ( k== i) continue;
          mx = max(mx, a[k]);
        }

        if ( mx >= a[i] )
        {
          for (int k=0; k<3; k++)
          {
            if ( k== i ) tmp += ( mx +1-a[i] );
            else tmp += (mx-a[k]);
          }
        }
        else
        {
          for (int k=0; k<3; k++)
          {
            if (k == i ) continue;
            else tmp += a[i]-1-a[k];
          }
        }
        ans = min (ans, tmp);
      }
      else if ( i == 0 && j == 2 )
      {
        long long tmp = 0;
        long long mx = max(a[0], a[1]);
        mx = max(mx, a[2]);
        for (int k=0; k<3; k++)
        {
          tmp += (mx-a[k]);
        }
        ans = min(ans, tmp);

      }
      else 
      {
        long long mx = max( a[i], a[j]);

        long long rem = -1;
        for (int k=0; k<3; k++)
        {
          if ( k == i || k == j );
          else rem = a[k];
        }

        long long tmp = 0;
        if ( rem >= mx )
        {
          for (int k=0; k<3; k++)
          {
            if ( k == i || k== j) 
            {
              tmp += (rem +1 - a[k] );
            }
          }
        }
        else
        {
          for (int k=0; k<3; k++)
          {
            if ( k == i || k== j)
            {
              tmp += (mx -a[k]);
            }
            else  tmp += ( mx -1 -a[k] );
          }
        }
        ans = min (ans, tmp);
      }
    }
  }
  cout << ans <<"\n";
}
