#include <stdio.h>

bool line[10001];
int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    for (int j=u; j<v; j++) line[j]=1;
  }
  int ans=0;
  for (int i=1; i<=1e4; i++)
  {
    if (line[i]) ans++;
  }
  printf("%d\n", ans);

}
