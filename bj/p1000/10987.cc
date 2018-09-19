#include <stdio.h>

char s[105];
int main()
{
    scanf("%s", s);
    int ans=0;
    for (int i=0; s[i]; i++)
    {
        if (s[i]== 'a') ans++;
        else if (s[i]=='e') ans++;
        else if (s[i]=='i') ans++;
        else if (s[i]=='o') ans++;
        else if (s[i]=='u') ans++;
    }
    printf("%d\n",ans);
}