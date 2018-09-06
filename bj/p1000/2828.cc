#include <stdio.h>

int a[21];
int main()
{
  int n, m, k; scanf("%d %d %d", &n, &m, &k);

  int now=1;
  int ans=0;
  for (int i=0; i<k; i++)
  {
    scanf("%d", &a[i]);

    if ( now+m-1 < a[i])
    {
      ans += (a[i]-now-(m-1));
      now = a[i]-(m-1);
    }
    else if ( now> a[i])
    {
      ans += (now-a[i]);
      now = a[i];
    }
  }
  printf("%d\n", ans);

}
