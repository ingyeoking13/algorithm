#include <iostream>

using namespace std;
int main()
{

  int tt=0;
  int T;
  cin >> T;
  while( ++tt <= T)
  {
    int n, m;
    cin >> n >> m;

    int mm = n/m;
    int nn = n- mm*m;

    long long ans =1;
    m-= nn;
    while(nn)
    {
      ans *= (mm+1);
      nn--;
    }
    while(m)
    {
      ans *= mm;
      m--;
    }
    cout << "#" << tt << " " << ans << "\n";
  }
}
