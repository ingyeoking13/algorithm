#include <stdio.h>
#include <algorithm>
using namespace std;

int a[(int)1e5];
int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }
  sort(a, a+n);
  char st=0;
  int ans=0;
  for (int i=n-1; i>=0; i--)
  {
    if (st==2) 
    {
      st=0;
    }
    else ans+= a[i], st++;
  }
  printf("%d\n", ans);

}
