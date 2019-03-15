#include <stdio.h>
#include <algorithm>

using namespace std;
long long sum=0;
int a[(int)1e5];

int main()
{
  int n, m; 
  scanf("%d %d", &n, &m);

  for (int i=0; i<n; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    sum += (long long)x;
    a[i] = x-y;
  }

  sort(a, a+n);

  int i=n-1;
  int ans=0;
  while(i>=0 && sum> m)
  {
    sum -= (long long)a[i];
    ans++;
    i--;
  }

  if(sum>m) return !printf("-1\n");
  else printf("%d\n", ans);

}
