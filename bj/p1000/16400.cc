#include <stdio.h>
#include <vector>

#define MOD 123456789
using namespace std;

bool p[(int)4e4+1];
vector<int> pr;
long long d[(int)4e4+1];
int main()
{
  for (int i=2; i<=4e4; i++)
  {
    if ( !p[i] )
    {
      pr.push_back(i);
      for (int j= i+i; j<=4e4; j+=i)
      {
        p[j] = 1;
      }
    }
  }

  d[0]=1;
  for (int i=0; i<pr.size(); i++)
  {
    for (int j=0; j<=4e4; j++)
    {
      if ( j- pr[i] <0 ) continue;
      d[j] = (d[j] + d[j-pr[i]])%MOD;
    }
  }

  int n;
  scanf("%d", &n);
  printf("%lld\n", d[n]);

}
