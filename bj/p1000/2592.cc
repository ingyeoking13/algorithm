#include <stdio.h>
#include <algorithm>

using namespace std;
int a[10];
int main()
{
    for (int i=0; i<10; i++) scanf("%d", &a[i]);
    sort(a, a+10);

    int s=0, bef, len=0, slen, sum=a[0];
    bef = a[0], s=a[0], slen=1, len=1;
    for (int i=1; i<10; i++)
    {
        sum += a[i];
        if (bef == a[i]) len++;
        else bef = a[i], len=0;
        if ( len > slen) slen=len, s = a[i];
    }
    printf("%d\n%d\n",sum/10, s);
}