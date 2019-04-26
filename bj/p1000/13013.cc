#include <stdio.h>

int a[50], b[51];
int main()
{
  int n; scanf("%d", &n);

  for (int i=0; i<n; i++) 
  {
    scanf("%d", &a[i]);
    b[a[i]] = i;
  }
  b[n] = -1;

  int ans =1;
  for (int i=0; i<n-1; i++)
  {
    if ( b[ a[ i ]  +1 ] >  b[ a[ i+1 ] + 1] ) ans++;
  }
  printf("%d\n", ans);
}
