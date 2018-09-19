#include <stdio.h>
int d[1000001];
int main()
{
    int n;
    scanf("%d", &n);
    d[0]=1;
    for (int i=1; i<=n; i++)
    {
        if (i-2>=0) d[i] += d[i-2];
        d[i] += d[i-1];
        d[i]%=15746;
    }
    printf("%d\n", d[n]);
}