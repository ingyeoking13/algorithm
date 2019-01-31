#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
  int k, c;
  scanf("%d%d", &k, &c);

  while(c--)
  {
    int m, n;
    scanf("%d%d",&m, &n);

    int mx = max(m,n);

    int curm=0, curn = 0;
    bool chk=0;

    for (int i=1; i<= mx; i++)
    {

      if ( curm < m ) curm++;

      if ( curm < curn  && curn-curm> k-i ) 
      {
        printf("0\n");
        chk=1;
        break;
      }

      if ( curn < n ) curn++;

      if ( (i < mx) && (curn < curm) && curm-curn > k-i )
      {
        printf("0\n");
        chk=1;
        break;
      }
      //printf("%d %d\n", curm, curn);
    }
    if (chk == 0) printf("1\n");
  }
}

