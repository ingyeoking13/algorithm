#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> ans(n);
  long long page=0;
  long long pos=0;

  for (int i=0; i<n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    int ansi= tmp/m;
    ans[i]=ansi;

    page += (long long)ansi;
    pos += ((long long)tmp)%m;

    if (pos>=m) 
    {
      pos -= (long long)m;
      ans[i] += 1LL;
    }
  }
  for (int i=0; i<ans.size(); i++)
  {
    printf("%d ", ans[i]);
  }
  printf("\n");

}
