#include <stdio.h>
#include <string.h>

char s[43];
int d[43];
int main()
{
    scanf("%s",(s+1));
    int len = strlen(s+1);
    if (s[1]=='0') return !printf("0\n");
    d[0]=d[1]=1;
    
    for (int i=2; i<=len; i++)
    {
        if (s[i]== '0' && s[i-1] >='4') return !printf("0\n");

        if ( 1<= s[i-1]-'0' && s[i-1]-'0' <= 3)
        {
            if (1 <= s[i-1]-'0' && s[i-1]-'0' <=2) 
            {
                if (s[i] =='0') d[i]=d[i-2];
                else d[i]=d[i-1]+d[i-2];
            }
            else if (s[i-1]-'0' == 3){
                if (s[i]=='0') d[i] = d[i-2];
                else if(  1 <=s[i]-'0' && s[i]-'0' <=4 ) d[i]=d[i-1]+d[i-2];
                else d[i]=d[i-1];
            } 
        }
        else d[i] = d[i-1];
    }
    printf("%d\n", d[len]);
}