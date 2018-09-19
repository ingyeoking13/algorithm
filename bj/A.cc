#include <stdio.h>

int cx[51], cy[51];
int difx[51], dify[51];
long long ansx=0, ansy=0;
long long gcd(long long a, long long b)
{
    return b?gcd(b, a%b):a;
}

int main()
{
    int n;
    scanf("%d", &n);
    int sx, sy;
    scanf("%d%d", &cx[0], &cy[0]);

    for (int i=1; i<=n; i++)
    {
        scanf("%d%d", &cx[i], &cy[i]);
        difx[i-1] = cx[i]-cx[i-1];
        dify[i-1] = cy[i] -cy[i-1];
    }
    
    int s, e;
    scanf("%d%d", &s, &e);

    int si=0,ei=0;
    for (int i=1; i<=n; i++)
    {
        if (cx[i]<s)  si=i;
        if (cx[i]<e)  ei=i;
    }
    printf("%d%d\n", si, ei);
    printf(".%lld\n", ansx);

    for (int i=si; i<=ei; i++)
    {
        printf("%d\n", i);
        printf("%lld..%lld sex\n", difx[i], ansx);
        long long gx= gcd((long long)difx[i], ansx);
        //long long tmpy= gcd((long long)cy[i], ansy);

        ansy = dify[i]*ansx/gx + ansy*difx[i]/gx;
        ansx = ansx*difx[i]/gx;
    }
    if (ansy %ansx ==0)
    {
        printf("%lld\n", ansy/ansx);
    }
    else {
        long long g = gcd(ansx, ansy);
        ansx/=g;
        ansy/=g;
        printf("%lld/%lld\n", ansy, ansx);
    }

}