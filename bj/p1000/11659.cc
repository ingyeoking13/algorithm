#include <stdio.h>

int a[(int)1e5], sum[(int)1e5];
int main()
{
    int n, m;
    scanf("%d%d",&n, &m);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    sum[0]=a[0];
    for (int i=1; i<n; i++) sum[i] = sum[i-1] + a[i];
    while(m--)
    {
        int f, t;
        scanf("%d %d", &f, &t);
        f--, t--;
        printf("%d\n", sum[t]-sum[f]+a[f]);
    }
}