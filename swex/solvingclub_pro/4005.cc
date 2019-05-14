#include <iostream>
#include <string.h>

using namespace std;

bool e[11][11];
bool v[11];
int mxLen =0;

int go(int now, int depth, int sz) 
{
  if ( depth > mxLen ) 
  {
     mxLen = depth;
  }

  for (int i=1; i<= sz; i++)
  {
    if (v[i]) continue;
    if ( !e[now][i] ) continue;

    v[i] = true;
    go(i, depth+1, sz);
    v[i] =false;
  }
}

int main()
{
  int T;
  int tt=0;

  cin >> T;
  while (++tt <= T)
  {
    memset(e, 0, sizeof(e));

    int n, k;
    cin >> n >> k;

    for (int i=0; i<k; i++)
    {
      int m;
      cin >> m;

      int a;
      cin >> a; 
      int prev = a;

      for (int j=0; j<m-1; j++)
      {
        cin >> a;
        e[prev][a] = true;
        prev = a;
      }
    }

    cout << "#" << tt << " ";
    for (int i=1; i<=n; i++)
    {
      int ans = 0;
      for (int j=1; j<=n; j++)
      {
        if (e[i][j]) ans++;
      }
      cout << ans << " ";
    }

    mxLen = 0;
    for (int i=1; i<=n; i++ )
    {
      v[i] =true;
      go(i, 1, n);
      v[i] =false;
    }

    cout << mxLen <<"\n";
  }
}
