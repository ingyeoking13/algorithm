#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    long long n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);

    printf("%lld\n", min(n*a, (n/2)*b+(n%2)*a));
  }
}
