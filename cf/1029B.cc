#include <stdio.h>

int a[(int)2e5];
char chk[(int)2e5];
int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  int mx=0;
  for (int i=0; i<n; i++)
  {
    if (chk[i]) continue;
    int now = a[i];
    int len=0;
    chk[i]=1;
    for (int j=i+1; j<n; j++)
    {
      if (now*2 <a[j]) 
      {
        break;
      }
      len++;
      chk[j]=1;
      now = a[j];
    }

    if (len+1 > mx ) mx =len+1;
  }
  printf("%d\n", mx);
}
