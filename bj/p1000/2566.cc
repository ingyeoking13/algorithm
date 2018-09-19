#include <stdio.h>

int main()
{
    int ans=0, x, y;
    for (int i=1; i<=9; i++)
    {
        for (int j=1; j<=9; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            if (tmp > ans)
            {
                x =i , y = j;
                ans=tmp;
            }
        }
    }
    printf("%d\n%d %d\n", ans, x, y);
}