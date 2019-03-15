#include <iostream>

using namespace std;
int main()
{
  int r, g, b;
  cin >> r >> g >> b;

  for (int i= r; i>=1; i--)
  {
    for (int j=g; j>=2; j--)
    {
      for (int k=b; k>=3; k--)
      {
        if ( i+1 == j && j+1== k)
        {
          cout << i+j+k << "\n";
          return 0;
        }
      }
    }
  }

}
