#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;
int main()
{
  int n, g, t;
  scanf("%d%d%d", &n, &t, &g);

  int visit[(int)1e5];
  memset(visit, -1, sizeof(visit));

  queue<int> q;
  q.push(n);
  visit[n]=0;

  while(!q.empty())
  {
    int now = q.front();
    q.pop();
    if (now == g) break;

    int next = now*2;
    if (next < 1e5)
    {

      int mxx=1;
      for (; mxx<=next; mxx*=10);
      mxx/=10;
      next-= mxx;
      if (visit[next]<0) visit[next] = visit[now]+1, q.push(next);
    }

    next = now+1;
    if (next>=1e5) continue;
    if (visit[next]<0) visit[next] = visit[now]+1, q.push(next);
  }

  if (visit[g]>t || visit[g] <0 ) printf("ANG\n");
  else printf("%d\n", visit[g]);

}
