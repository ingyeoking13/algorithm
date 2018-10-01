#include <stdio.h>

int main()
{
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    char ice=1;
    int ans=0;
    while(a!=b)
    {
        if ( a<0) ans +=c, a++;
        else if ( a== 0 && ice==1) {
            ans += d;
            ice =0;
        }
        else if ( a>=0)
        {
            ans+=e;
            a++;
        }
    }
    printf("%d\n", ans);
}