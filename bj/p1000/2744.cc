#include <stdio.h>

char s[101];
int main()
{
    scanf("%s", s);
    int i=0;
    while(s[i])
    {
        if ('A'<=s[i] && s[i]<='Z') s[i] = s[i] -'A'+'a';
        else s[i] = s[i] -'a' +'A';
        i++;
    }
    printf("%s", s);
}