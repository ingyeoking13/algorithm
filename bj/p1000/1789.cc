#include <stdio.h>

int main()
{
    long long n;
    scanf("%lld", &n);

    long long now =0, i=1;
    while(now+i<=n)
    {
        now+=i;
        i++;
    }
    printf("%d\n", i-1);
}