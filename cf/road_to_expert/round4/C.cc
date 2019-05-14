#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > e;

vector<int> a;
vector<int> called;
int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  e.resize(n);
  called.resize(m);
  a.resize(n);

  for (int i =0; i<n; i++)
  {
    e[i].resize(m);
    for (int j=0; j<m; j++)
    {
      int tmp =0;
      cin >> tmp;
      e[i][j] = tmp;
    }
  }

  while (k -- )
  {
    int user, chat;
    cin >> user >> chat;
    user --, chat --;

    called[chat] ++;
    a[user] --;

  }

  for (int i=0; i<n; i++)
  {
    int ans = 0;
    for (int j=0; j<m; j++)
    {
      if ( e[i][j] )
      {
        ans += called[ j ];
      }
    }
    ans += a[i];
    cout << ans << " ";
  }
  cout << "\n";
}
