#include <iostream>

using namespace std;
int a[101];
int main()
{
  for (int i=0; i<5; i++)
  {
    int tmp;
    cin >> tmp;
     a[tmp]++;
  }

  int ans = 0;
  for (int i=0; i<=100; i++)
  {
    if ( a[i] >=2 )
    {
      if ( a[i] == 2 )
      {
        if ( ans*a[ans] < a[i]*i ) ans = i;
      }
      else if ( ans*a[ans] < min(a[i], 3)*i )
      {
        ans = i;
      }
    }
  }

  if ( a[ans] == 2 ) a[ans] = 0;
  else a[ans] = a[ans]-3;

  ans = 0;
  for (int i=0; i<=100; i++)
  {
    ans += a[i]*i;
  }
  cout << ans <<"\n";
}
