#include <iostream>
#include <vector>

using namespace std;
char str[(int)3e5];
char tmp[(int)3e5];
int tmpidx[(int)3e5];

int main()
{
  int n;
  cin >> n;
  cin >> str;

  tmp[0] = str[0];
  tmpidx[0] = 0;
  for (int i=1; i<n; i++)
  {
    if ( tmp[i-1] > str[i] ) 
    {
      tmp[i] =tmp[i-1];
      tmpidx[i] = tmpidx[i-1];
    }
    else 
    {
      tmp[i] = str[i];
      tmpidx[i] = i;
    }
  }

  for (int i=0; i<n; i++)
  {
    if ( tmp[i] > str[i] )
    {
      cout << "YES\n" << tmpidx[i]+1 << " " << i+1 <<"\n";
      return 0;
    }
  }


  cout << "NO\n";
}
