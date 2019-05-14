#include <iostream>
#include <algorithm>

using namespace std;

bool lucky(int a)
{
  int tmp = a;
  if ( tmp < 0 ) tmp = -tmp;

  while (tmp)
  {
    int n = tmp%10;
    if ( n == 8 )
    {
      return true;
    }
    tmp/=10;
  }
  return false;
}

int main()
{
  int a;
  cin >> a;

  int upMin=16;
  for (int i=1; i<=16; i++)
  {
    if ( lucky(a+i ) )
    {
      upMin= i;
      break;
    }
  }
  cout << upMin << "\n";
}
