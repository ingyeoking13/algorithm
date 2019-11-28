#include <iostream>
#include <string.h>

using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int tc=1; tc<=T; tc++)
    {
        int n;
        cin>> n;
        char s[1001];
        cin >> s;

        int len = strlen(s);
        int cur =0;
        for (int i=0; i<len; i++)
        {
            if ( s[i] == ')') 
            {
                cur--;
            }
            else cur++;
        }
        int ans =0;
        cout << "#" << tc << " " << ans <<"\n";
    }
}