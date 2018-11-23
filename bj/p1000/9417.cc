#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
  return b?gcd(b, a%b):a;
}

int main()
{
  int T;
  scanf("%d\n", &T);
  char s[10*100+1];
  int dec[100];

  while(T--)
  {
    fgets(s, 10*100+1, stdin);
    int len = strlen(s); 
    int cnt=0;
    int tmp=0;

    for (int i=0; i<len; i++)
    {
      if ( s[i] == ' ' || s[i] =='\n')
      {
        dec[cnt++] = tmp;
        tmp=0;
      }
      else
      {
        tmp *= 10;
        tmp += (s[i]-'0');
      }
    }
    //dec[cnt++] = tmp;

    /*
    printf("%d\n", cnt);
    for (int i=0; i<cnt; i++) printf("%d ", dec[i]);
    printf("\n");
    */

    int ans=-1;
    for (int i=0; i<cnt; i++)
    {
      for (int j=i+1; j<cnt; j++)
      {
        ans = max (ans, gcd(dec[i], dec[j])) ;
      }
    }
    printf("%d\n", ans);

  }
}
