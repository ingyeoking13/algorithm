#include <stdio.h>
#include <string.h>

int d[(int)1e6];
char a[(int)1e6+1];
char b[(int)1e6+1];

int main()
{
  int n; scanf("%d", &n);

  scanf("%s", a);
  scanf("%s", b);

  memset(d, -1, sizeof(d));

  for (int i=0; i<n; i++)
  {
    if ( a[i] != b[i])
    {
      d[i] = a[i]-'0';
    }
  }

  int ans=0;
  for (int i=0; i<n-1; i++)
  {
    if ((d[i] != -1) && (d[i] == 1-d[i+1]))
    {
      d[i]=-1;
      d[i+1]=-1;
      ans++;
    }
  }

  for (int i=0; i<n; i++)
  {
    if (d[i] != -1) {
      ans++;
    }
  }
  printf("%d\n", ans);


}
