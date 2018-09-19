#include <stdio.h>

char a[100];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    int state = a[0];
    int ans=a[0];
    for (int i=1; i<n; i++)
    {
        if ( a[i]) 
        {
            ans = state+ a[i]+ ans;
            state++;
        }
        else state=0;
    }
    printf("%d\n", ans);

}