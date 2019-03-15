#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
struct cook
{
  long long c; int i;
  cook(long long c, int i) : c(c), i(i) {};
  cook() : c(0), i(0) {};
  bool operator < (const cook& a) const { return c <  a.c; }; 
};

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  vector<cook> cheapest(n);
  vector<long long> a(n); 
  vector<long long> c(n);

  for (int i=0;i<n; i++)
  {
    scanf("%lld", &a[i]);
  }
  for (int i=0; i<n; i++) 
  {
    scanf("%lld", &c[i]);
    cheapest[i].c = c[i];
    cheapest[i].i = i;
  }

  stable_sort(cheapest.begin(), cheapest.end());
  int cheapest_i =0;

  while(m--)
  {
    int dish, want;
    scanf("%d%d", &dish, &want);
    dish--;
    long long sell = 0;

    long long canSell = min((long long)want, a[dish]);
    sell += canSell*c[dish];

    want -= canSell;
    a[dish] -= canSell;

    bool chk=1;
    if ( want > 0 ) 
    {
      for (; cheapest_i< n && want >0; cheapest_i++)
      {
        int j = cheapest[cheapest_i].i;
        long long canSell = min((long long)want, a[j]);
        sell += canSell*c[j];
        want -= canSell;
        a[j] -= canSell;
      }

      if (want > 0 ) chk=0;
    }

    if( !chk ) sell =0;
    printf("%lld\n", sell);
  }
}
