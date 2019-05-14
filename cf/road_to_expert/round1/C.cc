#include <iostream>
#include <string.h>

using namespace std;

int d[16], a[3] = {4, 6, 9};
int main()
{
  memset(d, -1, sizeof(d));

  for (int i=1; i<=15; i++)
  {
    for (int j=0; j<3; j++)
    {
      if ( i>= a[j] &&  ans[i- a[j] ] != -1 )
      {
        ans[i] = max(ans[i], ans[i-j] +1 );
      }
    }
  }

  int T;
  cin >> T;

  while (T--)
  {
    int n;
    cin >> n;

    if ( n < 16 ) cout << ans[i] << "\n";
    else
    {
      int t= (n-16)/4 + 1;
      cout << t + ans[n-4*t] << "\n";
    }
  }

}
