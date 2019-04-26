#include <iostream>
using namespace std;

int sun[(int)2e5];
int main()
{
  int n, b, a;
  cin >> n >> b >> a;
  int mx = a;
  int c= a+b;

  for (int i=0; i<n; i++) 
  {
    cin >> sun[i];

  }

  for (int i=0; i<n; i++)
  {
    if ( a== 0  & b== 0) 
    {
      cout << i;
      return 0;
    }

    if ( !sun[i] )
    {
      if ( a== 0) b--;
      else a--;
    }
    else 
    {
      if ( b== 0 || a==mx) a--;
      else b--, a++;
    }
  }
  cout << n;
}
