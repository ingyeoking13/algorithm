#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int v[(int)5e5+1][2];
int main()
{
  int n, m ;
  scanf("%d%d", &n, &m);
  memset(v, -1, sizeof(v));

  queue<int> q;
  q.push(n);

  int t=0;
  v[n][0]=0;

  while(!q.empty())
  {
    int sz = q.size();
    t++;
    while(sz--)
    {
      int now = q.front();
      q.pop();

      if( now*2 <= (int)5e5) 
      {
        if( v[now*2][ t%2 ]<0) 
        {
          v[now*2][t%2]=t;
          q.push(now*2);
        }
      }

      if (now+1 <= (int)5e5) 
      {
        if( v[now+1][ t%2 ]<0)
        {
          v[now+1][t%2]=t;
          q.push(now+1);
        }
      }


      if (now-1 >= 0) 
      {
        if( v[now-1][ t%2 ]<0)
        {
          v[now-1][t%2]=t;
          q.push(now-1);
        }
      }
    }
  }

  t=0;
  while(m <= 5e5)
  {
    if ( v[m][t%2] >=0 &&  t>= v[m][t%2]  ) 
    {
      return !printf("%d\n", t);
    }
    m += (t+1);
    t++;
  }

  printf("-1\n");
}
