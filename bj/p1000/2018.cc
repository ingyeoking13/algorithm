#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ans=1;
    for (int i=2;i<=n; i++)
    {
        if ( i%2==0)
        {
            int m = n/i;
            if ( n%i != 0
            && 
            (
            (m*(i-1) + m+i/2 ==n )
            || 
            (m*(i-1) + m-i/2 == n)
            )
            ) ans++;
        }
        else 
        {
            int m = n/i;
            if ( n%i ==0 && m-i/2> 0) ans++;
        }
    }
    printf("%d\n", ans);
}