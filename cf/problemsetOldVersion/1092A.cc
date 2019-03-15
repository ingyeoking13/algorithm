#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i=0; i<k; i++)
    {
      for (int j=0; j<n/k; j++)
      {
        printf("%c", 'a'+i);
      }
    }
    for (int i=0; i<n%k; i++)
    {
      printf("%c", 'a');
    }
    printf("\n");
  }
}
