#include <stdio.h>

int a[500050];
int abs(int x) { return x>0?x:-x;}

int main()
{
  int n;
  scanf("%d", &n);
  int p=0, m=0, zero=0;

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    if (a[i]<0) m=1;
    else if (a[i]==0) zero=1;
    else p=1;
    a[i] = abs(a[i]);
  }

  long long ans=0;
  for (int i=0; i<n; i++) 
  {
    ans = ans + (long long)a[i];
  }

  if ((p==1 && m==0 && zero==0) || (p==0 && m==1 && zero==0))
  {
    int min=1e9+1;
    for (int i=0; i<n; i++)
    {
      if (min>a[i]) min = a[i];
    }
    ans= ans - (long long)(min);
    ans= ans - (long long)(min);
  }
  printf("%lld\n", ans);
}
