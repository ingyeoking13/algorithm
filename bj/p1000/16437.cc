#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> e[123457];
vector<long long> cnt;

long long go(int now)
{

  long long curcnt = cnt[now];
  long long wolf = 0;
  if ( curcnt <0 ) 
  {
    wolf = curcnt; 
    curcnt =0;
  }

  for (int i=0; i<e[now].size(); i++)
  {
    curcnt += go(e[now][i]); 
  }

  curcnt += wolf;
  if (curcnt<0) return 0;
  return curcnt;
}

int main()
{

  int n;
  scanf("%d", &n);
  cnt.resize(123456+1);

  for (int i=0; i<n-1; i++)
  {
    char w[3];
    int num, v;
    scanf("%s%d%d", w, &num, &v);
    e[v].push_back(i+2);

    if ( w[0] == 'W') num = -num;
    cnt[i+2] = num;
  }

  printf("%lld\n", go(1));
}
