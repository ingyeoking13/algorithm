#include <stdio.h>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
    return b?gcd(b, a%b):a;
}
int main()
{
    long long a, b, x, y;
    scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
    long long g = gcd(x, y);

    x/=g, y/=g;
    long long xx = x, yy=y;
    printf("%lld\n", min(a/xx, b/yy));
}