#include <stdio.h>

int n;
bool chk[10];
int a[10], b[10];
int ans=1e9;

void go(int now)
{
  if (now == n)
  {
    bool tmp=false;
    int aval=1, bval=0;
    for (int i=0; i<n; i++)
    {
      if ( chk[i] )
      {
        aval*=a[i];
        bval+=b[i];
        tmp =true;
      }
    }
    int diff = aval - bval;
    if ( diff <0 ) diff = -diff;
    if ( tmp && diff < ans ) ans = diff;
    return;
  }

  chk[now] =1;
  go(now+1);
  chk[now]=0;
  go(now+1);
}

int main()
{
  scanf("%d", &n);
  for (int i=0 ; i<n; i++)
  {
    scanf("%d %d", &a[i], &b[i]);
  }
  go(0);
  printf("%d\n", ans);

}
