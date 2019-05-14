#include <iostream>

using namespace std;

int main()
{
  long long n;
  cin >> n;

  long long s = 1;
  while ( s <= n )
  {
    n -= s;
    s++;
  }

  if ( n == 0)
  {
    cout << s-1 << "\n";
  }
  else cout << n <<"\n";
}
