#include <stdio.h>
#include <string.h>
char s1[1003], s2[1003];
int main()
{
    scanf("%s%s", s1, s2);
    int s1len = strlen(s1);
    int s2len = strlen(s2);

    if (s1len>= s2len) printf("go\n");
    else printf("no\n");

}