#include <stdio.h>
#include <string.h>

char s[10001];
int main()
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        int w=0, h=0;
        memset(s, 0, sizeof(s));
        for (int i=x1; i<=x2; i++) s[i]++;
        for (int i=x3; i<=x4; i++) s[i]++;
        for (int i=1; i<=10000; i++) if(s[i]==2) w++;

        memset(s, 0, sizeof(s));
        for (int i=y1; i<=y2; i++) s[i]++;
        for (int i=y3; i<=y4; i++) s[i]++;
        for (int i=1; i<=10000; i++) if(s[i]==2) h++;
        printf("%d\n",(x2-x1)*(y2-y1)-(w-1)*(h-1));
    }
}