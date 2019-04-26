#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
#define MOD (int)(1e9+7)

int p[(int)1e5];
int sz[(int)1e5];

struct Edge
{
  int u, v;
  Edge(int u, int v) : u(u), v(v){};
};
vector<Edge> e;

int ufind(int i)
{
  if (p[i] == i ) return i;
  return p[i] = ufind(p[i]);
};
long long pow(int n, int power)
{
  long long ret =1;
  long long bb = n;

  while (power)
  {
    if ( power%2 == 1)
    {
      ret*=bb;
      ret%=MOD;
      power--;
    }

    power/=2;
    bb*=bb;
    bb%=MOD;
  }
  return ret;

}

int main()
{
  int n, k;
  scanf("%d%d", &n,&k);
  for (int i=0; i<n; i++) 
  {
    p[i] = i, sz[i] = 1;
  }

  for (int i=0; i<n-1; i++)
  {
    int u, v, type;
    scanf("%d%d%d", &u, &v, &type);
    u--, v--;
    if (type == 1) continue;
    e.push_back( Edge(u, v) );
  }

  for (int i=0; i<e.size(); i++)
  {
    int u = e[i].u, v = e[i].v;
    u = ufind(u), v = ufind(v);
    p[u] = v;
    sz[p[v]] += sz[u];
  };

  bool chk[(int)1e5];
  memset(chk, 0, sizeof(chk));

  long long ans=0;
  for (int i=0; i<n; i++)
  {
    int ui =ufind ( i );
    if ( chk[ui] == true ) continue;
    chk[ui] = true;

    for (int j=1; j<=k-1; j++)
    {
      long long tmp =1;

      long long ret = pow(sz[ui], j);
      tmp *= ret;
      tmp%= MOD;

      tmp *= (n-sz[ui]);
      tmp %= MOD;

      if ( k-j-1 == 0) ret=1;
      else ret = pow(n, k-j-1);

      tmp *= ret;
      tmp %= MOD;

      ans += tmp;
      ans %= MOD;
    }
  }
  printf("%lld\n", ans);
};
