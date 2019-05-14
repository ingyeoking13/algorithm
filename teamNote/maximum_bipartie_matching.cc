/*
   maximum bipartie matching
   https://www.acmicpc.net/problem/2188
   https://www.acmicpc.net/problem/11375
*/

#include <iostream>
#define VERTEX (int)1e3

using namespace std;
struct Bipartie
{
  bool v[VERTEX];
  bool e[VERTEX][VERTEX];
  int pred[VERTEX];
  int n, m;

  Bipartie()
  {
    for (int i=0; i<VERTEX; i++)
    {
      for (int j=0; j<VERTEX; j++)
      {
        e[i][j] = false;
      }
      pred[i] = -1;
    }
  }

  int maximum_matching()
  {
    int ans=0;
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<m; j++) v[j]=false;
      if (go(i)) ans++;
    }
    return ans;
  }

  bool go(int cur)
  {
    if (cur == -1 ) return true;

    for (int i=0; i<m; i++)
    {
      if ( v[i] ) continue;
      if (e[cur][i])
      {
        v[i] = true;
        if ( go(pred[i]) ) 
        {
          pred[i] = cur;
          return true;
        }
      }
    }
    return false;
  }
};

Bipartie bipartie;

int main()
{

  int n, m;
  cin >> n >> m;
  bipartie.n = n;
  bipartie.m = m;
  for (int i=0; i<n; i++)
  {
    int t;
    cin >> t;
    while(t--)
    {
      int u;
      cin >> u;
      bipartie.e[i][u-1] = true;
    }
  }
  cout << bipartie.maximum_matching() << "\n";
}
