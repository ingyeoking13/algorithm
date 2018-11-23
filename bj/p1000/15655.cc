#include <stdio.h>
#include <algorithm>

using namespace std;
int a[8], in[8];

void go(int n, int m, int cnt, int peg)
{
  if (m == cnt)
  {
    for (int i=0; i<cnt; i++)
    {
      printf("%d ", a[i]);
    }
    printf("\n");
    return;
  }

  for (int i=peg; i<n; i++)
  {
    a[cnt]=in[i];
    go(n, m, cnt+1, i+1);
  }
}

int main()
{
  int n, m ;
  scanf("%d%d", &n, &m);
  for (int i=0; i<n; i++) scanf("%d", &in[i]);
  sort(in, in+n);
  go(n, m, 0, 0);
}

