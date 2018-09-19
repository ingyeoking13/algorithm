#include <stdio.h>
#define MAX 3*3*3*3*3*3*3
char s[MAX][MAX];
int a,b,c;
void go(int lx, int ly, int len)
{
    //printf("%d %d %d\n", lx, ly, len);
    char now = s[lx][ly];
    char chk= 0;
    for (int i=lx; i<lx+len; i++)
    {
        for (int j=ly; j<ly+len; j++){
            if ( now != s[i][j]) {
                chk=1;
                break;
            }
        }
        if (chk) break;
    }
    if (chk)
    {
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                go(lx+len/3*i, ly+len/3*j, len/3);
            }
        }
    }
    else if (now==-1) a++;
    else if (now==0) b++;
    else if (now==1) c++;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            scanf("%d", &s[i][j]);
    go(0, 0, n);
    printf("%d\n%d\n%d\n", a, b, c);
}