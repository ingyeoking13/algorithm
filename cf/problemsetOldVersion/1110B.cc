#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int a[(int)1e5];
int b[(int)1e5];
char cut[(int)1e5];
int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  if ( n== 1) printf("1\n");
  else if (k==1) printf("%d\n", a[n-1] - a[0] +1);
  else
  {
    priority_queue<pair<int, int> > pq;

    for (int i=0; i<n-1; i++) 
    {
      b[i] = a[i+1] - a[i];
      pq.push({b[i], i});
    }

    for (int i=0; i<(k-1); i++)
    {
      auto longest = pq.top();
      cut[longest.second] =1;
      pq.pop();
    }

    int cur=0;
    int ans=0;
    for (int i=0; i<n-1; i++)
    {
      if ( cut[i] )
      {
        ans += (cur+1);
        cur=0;
        continue;
      }
      cur += b[i];
    }
    ans += (cur+1);
    printf("%d\n", ans);
  }
}
