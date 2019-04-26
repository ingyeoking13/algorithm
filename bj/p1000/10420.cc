#include <stdio.h>
#include <algorithm>

int y = 2014, m = 4, d = 2;

using namespace std;

int month[13] = {
  0, 31, 28, 31, 30, 31, 
  30, 31, 31, 30, 31, 30, 31 };

int main()
{
  int days ;
  scanf("%d", &days);

  days--;

  while(days)
  {
    bool chk = (((y%4==0) && (y%100 !=0))|| y%400 == 0); // yoon

    int cur = month[m];
    if(m ==2)
    {
      if( chk ) cur++;
    }

    int diff =cur - d+1;
    if ( diff < days )
    {
      d+= diff;
      days -= diff;
    }
    else 
    {
      d+= days;
      days =0;
    }

    if ( d > cur ) m++, d%=cur; 
    if ( m == 13 ) y++, m=1;
  }

  char am[3], ad[3];
  am[2] = ad[2] = 0;
  for (int i=1; i>=0; i--)
  {
    am[i] = m%10 + '0'; m/=10;
    ad[i] = d%10 +'0'; d/=10;
  }
  printf("%d-%s-%s\n", y, am, ad);
}
