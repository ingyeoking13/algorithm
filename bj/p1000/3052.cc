#include <stdio.h>

char v[42];
int main()
{
    for (int i=0; i<10; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        v[tmp%42]=1;
    }
    int ans=0;
    for (int i=0; i<42; i++) if (v[i]) ans++;
    printf("%d\n",ans);
}