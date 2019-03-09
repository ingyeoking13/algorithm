#include <stdio.h>

int a[(int)1e5];
int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++) scanf("%d", &a[i]);

  int ans =0;
  for (int i=0; i<n-1; i++)
  {
    int l = i, r = i+1;
    int lstat = a[i], rstat = a[i+1];

    if (lstat == rstat) continue;
    int len = 0;
    while(l>=0 && r<n)
    {
      if ( (lstat == a[l]) && (rstat == a[r]) ) len+=2;
      else break;
      l--, r++;
    }

    if( len > ans ) ans = len;
  }
  printf("%d\n", ans);
}
