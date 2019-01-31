#include <stdio.h>
#include <algorithm>

using namespace std;

int a[(int)1e3];
int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  int ans=0, mn=1e7;
  for (int j=1; j<=1000; j++) // if I set ans to j,
  {
    int sum=0;
    for (int i=0; i<n; i++)
    {
      int mndiff=1e7; // diff is (a[i]-j) (+-) 1

      for (int k=-1; k<=1; k++)
      {
        int diff = abs(a[i]-j+k);
        mndiff = min(mndiff, diff);
      }

      sum += abs(mndiff);
    }
    if (sum < mn ) 
    {
      mn = sum, ans= j;
    }
  }
  printf("%d %d\n", ans, mn);
}
