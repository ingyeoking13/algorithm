/*
https://www.acmicpc.net/problem/11404
*/
#include <iostream>
#define VERTEX (int)5e2
#define MAXDIST (1e5)*(1e2)

using namespace std;
struct Floyd
{
  int d[VERTEX][VERTEX];
  int n;

  Floyd()
  {
    for (int i=0; i<VERTEX; i++)
    {
      for (int j=0; j<VERTEX; j++)
      {
        d[i][j] = MAXDIST+1;
        if ( i==j) d[i][j] = 0;
      }
    }
  };

  void floyd()
  {
    for (int k=0; k<n; k++)
    {
      for (int i=0; i<n; i++)
      {
        for (int j=0; j<n; j++)
        {

          if ( d[i][j] > d[i][k] + d[k][j] )
          {
            d[i][j] = d[i][k] + d[k][j];
          }

        }
      }
    }
  }

  void show()
  {
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++)
      {
        if ( d[i][j] >= MAXDIST+1 )  cout << "0 ";
        else  cout << d[i][j] << " ";
      }
      cout << "\n";
    }
  }
};

Floyd floyd;

int main()
{
  ios::sync_with_stdio(false);
  cin >> floyd.n;
  int m;
  cin >> m;

  while (m-- )
  {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    if (w < floyd.d[u][v]) floyd.d[u][v] = w;
  }

  floyd.floyd();
  floyd.show();
}
