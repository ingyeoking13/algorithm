#include <stdio.h>

int cnt[(int)5e3+1];
int a[(int)5e3+1];
bool used[(int)5e3+1][(int)5e3+1];

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);

  int mx =0;
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    cnt[a[i]]++;

    if ( mx < cnt[a[i]] )  mx = cnt[a[i]];
  }

  if (mx > k )
  {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");

  int col=0;
  for (int i=0; i<n; i++)
  {
    while ( used[a[i]][col+1] ) 
    {
      col++;
      col%=k;
    }

    printf("%d ", col+1);
    used[a[i]][col+1] = true;

    col++;
    col%=k;
  }
  printf("\n");

}
