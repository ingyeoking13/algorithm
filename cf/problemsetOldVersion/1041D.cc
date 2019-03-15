#include <stdio.h>
#include <vector>

using namespace std;
int a[(int)2e5], b[(int)2e5];
int sum[(int)2e5]; // up air stream range sum

int main()
{
    int n, h; scanf("%d %d", &n ,&h);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }

    sum[0] = b[0]-a[0];
    for (int i=1; i<n; i++) sum[i] = sum[i-1] + b[i]-a[i];

    int ans=0;
    int i;
    int ed=0;
    for (i=0; i<n; i++)
    {
        int nowx = a[i];
        int nowh = h;

        int j=ed+1;
        if (i>0 ) nowh -= (a[ed] -a[i] - (sum[ed-1]-sum[i-1]));

        while(j<n && a[j] -b[j-1] < nowh )
        {
            nowh = nowh - a[j] + b[j-1];
            nowx = a[j];
            j++;
        }

        if ( nowh>0) nowx = nowx + (b[j-1]-nowx+ nowh);
        if (nowx-a[i]> ans) ans=nowx-a[i];
        ed=j-1;
    }
    printf("%d\n", ans);
}