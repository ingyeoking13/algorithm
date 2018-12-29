#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long a[301][301];
int main()
{
  int n, m;
  cin >> n >> m;

  for (int i=0; i<n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x][y] = m-x-y;
    if (a[x][y] <0) a[x][y]=0;
  }

  for (int i=1; i<=300; i++)
  {
    a[0][i] += a[0][i-1];
    a[i][0] += a[i-1][0];
  }

  for (int i=1; i<=300;i++)
  {
    for (int j=1; j<=300; j++)
    {
      a[i][j] = max(a[i-1][j]+a[i][j], a[i][j-1] +a[i][j]);
    }
  }
  cout << a[300][300] <<"\n";

}
