#include <stdio.h>

int d[21];
int main()
{
    int n;
    scanf("%d", &n);
    d[1] =1;
    for (int i=2; i<=n; i++)
    {
        d[i] = d[i-1] + d[i-2];
    }
    printf("%d\n", d[n]);
}