#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char s1[(int)5e2+1], s2[(int)5e2+1];
int d[(int)5e2+1][(int)5e2+1];
int n;

/*
int go(int i, int j )
{
  if ( i == n || j == n ) return 0;

  if ( d[i][j] >=0 ) return d[i][j];
  d[i][j] = 0;

  int ret = 0;
  if ( s1[i] == s2[j] ) ret = go (i+1, j+1)+1;

  ret = max (ret, go(i+1, j));
  ret = max (ret, go(i, j+1));

  return d[i][j] = ret; 

};
*/

int main()
{

  //ios::sync_with_stdio(false);
  int tt=0;
  int T;
  cin >> T;

  while ( ++tt <= T)
  {
    cin >> n;
    memset(d, 0, sizeof(d));

    cin >> s1 >> s2;

    for (int i=0; i<n ;i++)
    {
      for (int j=0; j<n; j++)
      {
        if ( s1[i] == s2[j] ) d[i+1][j+1] = d[i][j]+1;
        d[i+1][j+1] = max(d[i+1][j], d[i+1][j+1]);
        d[i+1][j+1] = max(d[i][j+1], d[i+1][j+1]);
      }
    }

    printf("#%d %.2lf\n", tt, ((double)d[n][n]/n)*100);
  }
}
