#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s[(int)1e5+1];
int main()
{
    scanf("%s",s);
    int len = strlen(s);
    sort(s, s+len);

    int tmp=0, z=0;
    for (int i=0; i<len; i++)
    {
        if (s[i]=='0') z++;
        tmp += s[i]-'0';
    }
    if (tmp%3==0 && z>0)
    {
        for (int i=len-1; i>=0; i--) printf("%c", s[i]);
        printf("\n");
    }
    else printf("-1\n");
}