#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;

  while(T--)
  {
    long long l, r;
    cin >> l >> r;

    bool chk=0;
    for (long long i = l ; i<r; i++)
    {
      for (long long j = i+i; j<=r; j+= i)
      {
        cout << i << " " << j << "\n";
        chk=1;
        break;
      }
      if (chk) break;
    }
  }
}
