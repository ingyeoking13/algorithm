#include <iostream>

using namespace std;

char s[(int)1e5+1];
char ans[(int)11];
int n;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0; i<10; i++) ans[i] ='0';
    ans[10] = 0;

    cin >> n >> s;
    for (int i=0 ; i<n; i++)
    {
        if ( s[i] == 'L') 
        {
            for (int j=0; j<10; j++)
            {
                if (ans[j]=='0')
                {
                    ans[j] ='1';
                    break;
                }
            }
        }
        else if (s[i] == 'R')
        {
            for (int j=9; j>=0; j--)
            {
                if (ans[j]=='0')
                {
                    ans[j] ='1';
                    break;
                }
            }

        }
        else 
        {
            int m = s[i]-'0';
            ans[m] = '0';
        }
    }
    cout << ans <<"\n";

}