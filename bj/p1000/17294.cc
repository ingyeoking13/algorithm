#include <iostream>
#include <string.h>

using namespace std;
char s[20];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>> s;
    int len =strlen(s);
    bool ans= true;
    int d= s[1] - s[0];
    for (int i=0; i<len-1; i++)
    {
        int val = s[i+1] - s[i];
        if ( val!=d) ans = false; 
    }

    if (ans )
    {
        cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    }
    else cout <<"흥칫뿡!! <(￣ ﹌ ￣)>";

}