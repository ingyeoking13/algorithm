#include <iostream>
#include <string.h>

using namespace std;

char s[(int)1e5+1], s2[(int)1e5+1];
int al[26], al2[26];
int main()
{
    int T;
    cin >> T;
    for (int tc=1; tc<=T; tc++)
    {
        memset(al, 0, sizeof(al));
        memset(al2, 0, sizeof(al2));

        cin >> s >> s2;

        int len = strlen(s);
        int len2= strlen(s2);

        for (int i=0; i<len; i++)
            al[s[i]-'a']++;
        
        for (int i=0; i<len; i++)
            al2[s2[i]-'a']++;


        bool yes=true;
        for (int i=0; i<26; i++)
        {
            if ( al[i] != al2[i]) 
                yes = false;
        }

        int ans = yes;
        for (int j=len; j<len2; j++)
        {
            al2[s2[j]-'a']++;
            al2[s2[j-len]-'a']--;

            yes= true;
            for (int i=0; i<26; i++)
            {
                if ( al[i] != al2[i]) 
                {
                    yes= false;
                    break;
                }
            }
            if (yes) ans++;
        }

        cout << "#" << tc << " " << ans <<"\n";
    }
}