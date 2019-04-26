#include <bits/stdc++.h>
#define MOD 100030001
using namespace std;

long long d[301][301];
long long go(int rem, int height)
{
  if ( rem == 0 ) return 1;
  if ( height == 0) return 0;

  if (d[rem][height] >=0 ) return d[rem][height];
  d[rem][height]=0;

  long long ret=0;
  for (int i= 0; i<=rem-1; i++)
  {
    ret += (go(i, height-1)*go(rem-1-i, height-1))%MOD;
    ret %= MOD;
  }

  return d[rem][height] = ret;
};

int main()
{
  memset(d, -1, sizeof(d));

  int n, h;
  cin >> n >> h;
  cout << (go(n, h) - go(n, h-1)+MOD)%MOD <<"\n";
}
