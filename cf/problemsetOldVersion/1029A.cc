#include <stdio.h>

char s[51];
int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  int len=0;
  for (int i=1; i<n; i++)
  {
    int chk=0;
    for (int j=0; j<n-i; j++)
    {
      if (s[i+j] != s[j]) 
      {
        chk=1;
        break;
      }
    }

    if (!chk) 
    {
      if (len < n-i)  len = n-i;
    }
  }

  for (int i=0; i<k-1; i++)
  {
    for (int j=0; j<n-len; j++)
    {
      printf("%c", s[j]);
    }
  }
  for (int i=0; i<n; i++) printf("%c", s[i]);
  printf("\n");
}
