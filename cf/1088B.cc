#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{

  int n, k;
  scanf("%d %d", &n, &k);
  int a[(int)1e5];
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }
  sort(a, a+n);

  int nowsum=0;
  for (int i=0; i<n && k>0; i++)
  {
    int now = a[i];
    int j =i+1;

    while(j<n && now == a[j])
    {
      j++;
    }

    printf("%d\n", now-nowsum);

    k--;
    nowsum += (now-nowsum);
    i=j-1;
  }
  while(k-->0) printf("0\n");

}
