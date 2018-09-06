#include <stdio.h>
int main()
{
  int n; scanf("%d", &n);
  int cnt=0, before=0;
  int ans[1000], idx=0;

  for (int i=0; i<n ;i++)
  {
    int tmp; scanf("%d", &tmp);
    if (before<tmp)
    {
      cnt++;
      before=tmp;
    }
    else
    {
      ans[idx++]=cnt;
      cnt=1;
      before=1;
    }
  }
  ans[idx++]=cnt;
  printf("%d\n", idx);
  for (int i=0; i<idx; i++)
  {
    printf("%d ", ans[i]);
  }
  printf("\n");

}
