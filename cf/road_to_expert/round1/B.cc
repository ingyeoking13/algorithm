#include <iostream>

char s[300][302];

using namespace std;
int main()
{
  int n;
  cin >> n;

  for (int i=0; i<n; i++)
  {
    cin >> s[i];
  }

  char p = s[0][0];
  char a = s[0][1];
  if ( p == a )
  {
    cout << "NO\n";
    return 0;
  }

  char chk =true;
  for (int i=0; i<n; i++)
  {
    if ( s[i][i] != p ) chk= false;
    if ( s[i][n-i-1] != p ) chk =false;
    s[i][i] = s[i][n-i-1] = a;
  }

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      if ( s[i][j] != a ) chk =false;
    }
  }

  if ( chk ) cout << "YES\n";
  else cout << "NO\n";
}
