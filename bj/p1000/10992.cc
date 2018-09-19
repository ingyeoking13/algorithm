#include <stdio.h>

char s[100][200];
int main()
{
    int n; scanf("%d", &n);
    int x=0, y=n-1;

    for (int i=0; i<n; i++)
        for (int j=0; j<=y+i; j++)
            s[i][j]=' ';

    for (int i=0; i<n;i++) s[x+i][y-i]='*';
    for (int i=0; i<n;i++) s[x+i][y+i]='*';
    for (int i=0; i<2*n-1; i++) s[x+n-1][i] ='*';

    for (int i=0; i<n; i++)
        printf("%s\n", s[i]);
}