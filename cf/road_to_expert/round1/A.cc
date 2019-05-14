#include <iostream>

using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  int y = 1;
  while ( k > 2*m )
  {
    k-= 2*m;
    y++;
  }

  int x =0;
  while ( --k )
  {
    x++;
  }

  char LR;
  if ( x%2 == 0) LR = 'L';
  else LR = 'R';
  cout << y <<  " "<< x/2 +1 << " " <<  LR <<"\n";

}
