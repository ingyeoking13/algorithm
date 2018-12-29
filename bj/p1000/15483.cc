#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
string f, t;
int d[(int)1e3][(int)1e3];

int go(int i, int j)
{
  if ( i == f.size() && j== t.size()) return 0;
  else if ( i==f.size() || j==t.size() ) 
  {
    if ( i== f.size() ) return t.size() - j;
    else return f.size() - i;
  }

  if (d[i][j] >=0) return d[i][j];

  d[i][j]=0;
  int mn =1e9;
  if ( f[i] == t[j] ) return d[i][j]= go(i+1,j+1);
  else
  {
    mn = min(mn, go(i+1, j)+1); // delete
    mn = min(mn, go(i, j+1)+1); // add
    mn = min(mn, go(i+1,j+1)+1); // replace
  }
  return d[i][j] = mn;
}

int main()
{
  cin >> f >> t;
  memset(d, -1, sizeof(d));
  cout << go(0, 0) << "\n";
}
