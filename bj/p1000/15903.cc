#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<long long> pq;
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i=0; i<n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    pq.push(-tmp);
  }
  while(m--)
  {
    long long a= pq.top();
    pq.pop();
    long long b= pq.top();
    pq.pop();
    pq.push(a+b);
    pq.push(a+b);
  }

  long long ans=0;
  while(!pq.empty())
  {
    ans += pq.top();
    pq.pop();
  }
  printf("%lld\n", -ans);

}
