#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    int k; scanf("%d", &k);
    long long r = k-1;
    long long l = 2;
    bool chk=0;
    while ( l<= r) 
    {
      long long sum = (r+l)*(r-l+1)/2;
      if ( sum == k) 
      {
        chk=1;
      }
      else if (sum> k) r--;
      else l++;
    }
      


  }


}
