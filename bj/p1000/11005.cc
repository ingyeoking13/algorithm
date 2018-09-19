#include <stdio.h>

char a[15];
char map[26];

int main()
{
    int n, b;
    scanf("%d %d", &n, &b);
    for (int i=0; i<26; i++) map[i]='A'+i;

    int i=0;
    int mok=n, rem;
    while(mok)
    {
        rem = mok%b;
        mok = mok/b;
        a[i++]= rem;
    }

    for (int j=i-1; j>=0; j--)
    {
        if ( a[j] >= 10) printf("%c", map[a[j]-10]);
        else printf("%d", a[j]);
    }
    printf("\n");

}