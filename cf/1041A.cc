#include <stdio.h>
#include <algorithm>

using namespace std;
int a[1001];
int main()
{
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    int now = a[0], ans =0;
    for (int i=1; i<n; i++)
    {
        if (a[i]-a[i-1] != 1)
        {
            ans += (a[i] -a[i-1]);
        }
    }
    printf("%d\n", ans);
}