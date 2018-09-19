#include <stdio.h>
#include <string.h>

int main()
{
    char s[102];
    while(fgets(s,102,stdin))
    {
        int a, b, c,d;
        a=b=c=d=0;
        int len= strlen(s);
        for (int i=0;i<len; i++)
        {
            if ('A'<=s[i] && s[i]<='Z') b++;
            else if ('a' <= s[i] && s[i]<='z') a++;
            else if ('0' <= s[i] && s[i]<='9') c++;
            else if (s[i] == ' ') d++;
        }
        printf("%d %d %d %d\n",a,b,c,d);
    }
}