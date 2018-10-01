//failed
#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);
    unsigned long long tmp=0, tmpn=0;
    for (int i=0; i<n; i++)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        tmp += (unsigned long long)a*b;
        tmpn += b;
    }
    printf("%llu\n", tmp/tmpn + (tmp%tmpn?1:0));
}