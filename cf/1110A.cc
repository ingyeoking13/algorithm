#include <stdio.h>

int a[(int)1e5];
char a_odd[(int)1e5];
int main()
{
  int b, k;
  scanf("%d%d", &b, &k);
  for (int i=0; i<k; i++)
  {
    scanf("%d", &a[i]);
  }

  int odd=1;
  if ( b%2 == 0) odd=0;

  for (int i=0; i<k-1; i++)
  {
    a_odd[i] = ((a[i]%2 == 1) && odd);
  }
  a_odd[k-1] = (a[k-1]%2 == 1);

  int ans=0;

  for (int i=0; i<k; i++)
  {
    ans += a_odd[i];
  }

  if ( ans%2 ) printf("odd\n");
  else printf("even\n");

}
