#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

priority_queue<int> pq;
int main()
{
  int n, k;
  scanf("%d%d", &n, &k);

  int mincnt=0;
  for (int i=1; i<=n; i<<=1)
  {
    if ( n&i ) 
    {
      mincnt++;
      pq.push(i);
    }
  }

  if (mincnt > k || n < k )
  {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  int cnt = mincnt;

  while(k>cnt)
  {
    int diff = k-cnt;
    diff++;

    int pooo = pq.top();
    pq.pop();

    int tmp=1;
    for (;tmp<=diff && pooo>=1; tmp*=2) pooo/=2;

    if (pooo==0) pooo++;
    else pooo*=2;
    tmp/=2;

    for (int i=0; i<tmp; i++) pq.push(pooo);
    cnt += (tmp-1);
  }

  stack<int> ans;
  while(!pq.empty())
  {
    int now =pq.top();
    pq.pop();
    ans.push(now);
  }

  while(!ans.empty())
  {
    int now = ans.top();
    ans.pop();
    printf("%d ", now);
  }
}
