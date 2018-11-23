#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
#define MOD ((int)1e9+7)

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    int n;
    scanf("%d", &n);
    priority_queue<long long> pq;

    for (int i=0; i<n; i++)
    {
      long long tmp;
      scanf("%lld", &tmp);
      pq.push(-tmp);
    }

    long long ans=1;
    while(pq.size() != 1)
    {
      long long a = pq.top();
      pq.pop();
      long long b = pq.top();
      pq.pop();
      a= -a, b= -b;
      long long tmp = ((a%MOD) * (b%MOD))%MOD;
//      printf("%lld %lld : %lld\n", a, b, tmp);

      pq.push(-tmp);
      ans= ((ans%MOD)*(tmp%MOD))%MOD;
    }
    printf("%lld\n", ans);
  }
}
