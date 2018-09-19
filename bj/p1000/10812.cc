#include <stdio.h>

long long d[68];
int main()
{
    d[0]= d[1]=1;
    d[2] =2; d[3]=4;

    for (int i=4; i<68; i++)
    {
        d[i]= d[i-1]+d[i-2]+d[i-3] +d[i-4];
    }

    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", d[n]);
    }
}