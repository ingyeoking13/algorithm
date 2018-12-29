#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  int a[(int)2e5];
  int b[(int)2e5];
  int c[(int)2e5];

  int mx=0;
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    if (a[i] > mx) mx = a[i];
  }

  for (int i=0; i<n; i++) 
  {
    b[i] = mx-a[i];
    c[i] = mx+1-a[i];
  }

  for (int i=0; i<n; i++)
  {
    if (a[i]%2) a[i]=1;
    else a[i]=0;

    b[i]=c[i]=a[i];
    printf("%d", a[i]);
  }
  printf("\n");

  for (int i=0; i<n; i++)
  {
    if (a[i])
    {
      if ( i+1 <n ) 
      {
        if (a[i+1]) 
        {
          b[i] = b[i+1] = 0;
          i++;
        }
      }
    }
  }

  bool chk=1;
  for (int i=0; i<n; i++)  

  if (chk)
  {
    printf("YES\n");
    return 0;
  }

  chk=1;
  for (int i=0; i<n; i++)
  {
    if (a[i]==0)
    {
      if (i+1 <n )
      {
        if (a[i+1]==0) i++;
        else chk=0;

      }
      else chk=0;
    }
    if (chk==0) break;
  }
  if (chk) printf("YES\n");
  else printf("NO\n");

}
