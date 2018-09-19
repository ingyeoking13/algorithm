#include <stdio.h>
#include <algorithm>

using namespace std;

int a[(int)3e5];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    sort(a, a+n);
    int cnt=0;
    long long ans=0;
    for (int i=0; i<n; i++)
    {
        ans += (a[i]*(long long)cnt);
        if (cnt<k) cnt++;
    }
    printf("%lld\n", ans);
}