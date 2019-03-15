#include <stdio.h>

char s[(int)2e5+1];
char chk[(int)2e5+1];
int main()
{
  int n; scanf("%d", &n);
  scanf("%s", s);

  bool ans=0;
  for (int i=0; i<n-1; i++)
  {
    if (s[i] > s[i+1]) 
    {
      ans=1;
      chk[i]= 1;
      break;
    }
  }

  if (!ans) chk[n-1]=1;

  for (int i=0; i<n; i++)
  {
    if (!chk[i]) 
    {
      printf("%c", s[i]);
    }
  }
  printf("\n");

}
