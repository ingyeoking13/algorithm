#include <iostream>
#include <string.h>

using namespace std;
char ans[5][62];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char s[16];
    cin >> s;
    int len = strlen(s);

    int col= 0;
    for (int i=1; i<=len; i++)
    {
        if (col>0) col--;
        ans[0][col] = ans[0][col+1]=
        ans[0][col+3] = ans[0][col+4]= '.';
        ans[0][col+2] = '#';

        ans[1][col] = ans[1][col+2] = ans[1][col+4] ='.';
        ans[1][col+1] = ans[1][col+3] ='#';

        ans[3][col+1] = ans[3][col+3] ='#';
        ans[3][col] = ans[3][col+2] = ans[3][col+4] ='.';

        ans[2][col] ='#';
        ans[2][col+1] = ans[2][col+3] ='.';
        ans[2][col+2] = s[i-1];
        ans[2][col+4] ='#';

        ans[4][col] = ans[4][col+1]=
        ans[4][col+3] = ans[4][col+4]= '.';
        ans[4][col+2] = '#';
        col+=5;
    }
    ans[0][col]= ans[4][col] = 0;
    ans[1][col] = ans[3][col] = ans[2][col]= 0;

    col= 0;
    for (int i=1; i<=len; i++)
    {
        if ( col>0) col--;
        if ( i%3 == 0)
        {
            ans[1][col+1] = ans[1][col+3] = '*';
            ans[3][col+1] = ans[3][col+3] = '*';
            ans[2][col] = ans[2][col+4]= '*';
            ans[0][col+2] = ans[4][col+2] ='*';
        }
        col+=5;
    }
    
    for (int i=0; i<5; i++) cout << ans[i]<<"\n";
}