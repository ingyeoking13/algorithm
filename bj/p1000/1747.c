#include <stdio.h>

char p[1111112];
char ans[1111112];
int main()
{
  for (int i=2; i<=1111111; i++)
  {
    if (!p[i])
    {
      int tmp = i;
      char palin[10];
      int len=0;

      while(tmp)
      {
        palin[len++] = tmp%10;
        tmp/=10;
      }

      int chk=1;
      for (int j=0; j<len/2; j++)
      {
        if (palin[j] != palin[len-j-1]) chk=0;
      }
      if (chk) ans[i]=1;

      for (int j=i*2; j<=1111111; j+=i)
      {
        p[j]=1;
      }
    }
  }


  int n; 
  scanf("%d", &n);
  for (int i=n; i<=1111111; i++)
  {
    if ( ans[i] ) 
    {
      printf("%d\n", i);
      break;
    }
  }

}
