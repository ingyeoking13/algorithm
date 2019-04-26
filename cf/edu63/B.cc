#include <iostream>
#include <vector>

using namespace std;

char str[(int)1e5];
vector<int> v[10];
int st[10];
int main()
{
  int n;
  cin >> n;

  cin >> str;

  for (int i=0; i<n; i++)
  {
    v[str[i]-'0'].push_back(i);
  }

  int turn = (n-11)/2;
  if ( turn >= v[8].size() ) 
  {
    cout << "NO\n";
    return 0;
  }

  for (int i=0; i<turn; i++)
  {
    int mn =1e9, val=-1;
    for (int j=0; j<10; j++)
    {
      if ( j == 8) continue;
      int k=st[j];
      if ( k >= v[j].size() ) continue;
      int idx = v[j][k];
      if ( mn > idx ) 
      {
        mn =idx, val = j;
      }
    }
    st[val]++;
    st[8]++;
  }

  for (int i=0; i<10; i++)
  {
    for (int j=0; j<st[i]; j++)
    {
      str[ v[i][j] ]='?';
    }
  }

  for (int i=0; i<n; i++)
  {
    if ( str[ i ] == '?') continue;
    if ( str[ i ] == '8' )
    {
      cout << "YES\n";
      break;
    }
    else 
    {
      cout << "NO\n";
      break;
    }
  }
}
