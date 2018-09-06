#include <stdio.h>
#include <algorithm>

using namespace std;

int a[101];
int k;
int chk[101];

int n, m;
int personassign[101];
pair<int, int> cnt[101];

int ans=0;

void go(int now, int person)
{
  if (person == 0) 
  {

    int day=1e9;
    for (int i=100; i>100-k; i--)
    {
      if ( personassign[i] == 0) continue;

      day = min(day, cnt[i].first/personassign[i]);
    }

    ans = max(ans, day);
    return ;
  }

  for (int i =now; i>100-k; i--)
  {
    personassign[i]+=1;
    go(now, person-1);
    personassign[i]-=1;
  }

  return;
}


int main()
{
  scanf("%d %d", &n, &m);

  for (int i=1; i<=100; i++)
  {
    cnt[i].second= i;
  }

  for (int i=0; i<m; i++)
  {
    scanf("%d", &a[i]);
    if (!chk[a[i]]) 
    {
      k++;
      chk[a[i]]=1;
    }
    cnt[a[i]].first++;
  }

  if ( n>m ) return !printf("0\n");

  sort(cnt, cnt+101);

  for (int i=100; i>100-k; i--)
  {
    personassign[i]+=1;
    go(i, n-1);
    personassign[i]-=1;
  }
  printf("%d\n", ans);

}
