#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> e[(int)1e5+1];
bool leaf[(int)1e5+1];
int cnt[(int)1e5+1]; // leaf count

int go(int now)
{
  int ret=0;
  bool chk=1;

  for (auto i : e[now] )
  {
    chk=0;
    ret += go(i);
  }

  if (chk==1) 
  {
    leaf[now] =1;
    cnt[now] =1;
    return cnt[now];
  }

  return cnt[now] =ret;
}
int main()
{
  int n;
  scanf("%d",&n);
  for (int i=2; i<=n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    e[tmp].push_back(i);
  }

  cnt[1] = go(1);

  sort(cnt+1, cnt+n+1);
  for (int i=1; i<=n; i++)
  {
    printf("%d ", cnt[i]);
  }

  printf("\n");

}
