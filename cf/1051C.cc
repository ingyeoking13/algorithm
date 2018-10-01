#include <stdio.h>

int a[100], cnt[101], kk[4];
char three_disabled[101];
char three_use_another_direct[101];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    for (int i=1; i<=100; i++)
    {
        if (cnt[i]<3) kk[cnt[i]]++;
        else kk[3]++;
    }

    if ((kk[1] + kk[3])%2==1)
    {
        if ( kk[3]==0) return !printf("NO\n");
        for (int i=0; i<n; i++) 
        {
            if (cnt[a[i]]>=3) 
            {
                three_disabled[a[i]]=1;
                break;
            }
        }
    } 

    printf("YES\n");
    int my_count = (kk[1]+kk[3])/2;
    for (int i=0; i<n; i++)
    {
        int now = cnt[a[i]];
        if ( now == 1 || now >= 3)
        {
            if (now >= 3) 
            {
                if (three_disabled[a[i]]) printf("B");
                else if (my_count>0 && three_use_another_direct[a[i]]==0)
                {
                    printf("A");
                    three_use_another_direct[a[i]]='B';
                    my_count--;
                }
                else if (three_use_another_direct[a[i]]==0)
                {
                    printf("B");
                    three_use_another_direct[a[i]]='A';
                }
                else printf("%c", three_use_another_direct[a[i]]);
            }
            else if (my_count>0)  //now==1
            {
                printf("A");
                my_count--;
            }
            else printf("B");
        }
        else printf("B");
    }
    printf("\n");
}