#include <bits/stdc++.h> 
using ll = long long;

using namespace std;
char s[500];
int main()
{
    cin >> s;
    int len =strlen(s);

    char t[500];
    int mn = 1e9;

    for (int i=0; i<len; i++)
    {
        strcpy(t, s);

        for (int j=0; j<5; j++)
        {
            t[i] = 'a' +j;
            int cnt = 0;

            int l =i-1, r =i+1;
            char lc ;
            if ( l > 0 ) lc = s[l];
            while( l>=0 && s[l] == lc )
            {
                t[l] = 'a' + j;
                l++;
            }

            char rc;
            if ( r <len) rc = s[r];
            while( r< len && s[r] == rc) 
            {
                t[r] = 'a'+j;
                r++;
            }

            bool ff = true;
            for (int k=0; k<len; k++)
            {
                if ( t[k] != 'a' +j) ff = false;
            }

        }

    }

}
