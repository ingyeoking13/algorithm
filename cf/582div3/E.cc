#include <iostream>
#include <string.h>

using namespace std;
char s[2][3];
bool e[3][3] ={ 
    { 1, 1,1 },
    { 1, 1,1 },
    { 1, 1,1 }
};

bool v[3];
char cycle[4];

bool go (int cur, int len)
{
    if ( v[0] == v[1] && v[1] == v[2] && v[2] == true) return true;

    for (int i=0; i<3; i++)
    {
        if ( !e[cur][i]) continue;
        if (v[i]) continue;

        v[i] = true;
        cycle[len+1] = i+'a';

        if (go(i, len+1)) return true;

        cycle[len+1] = 0;
        v[i] = false;
    }
    return false;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >>n;
    cin >> s[0] >> s[1];

    for (int i = 0; i<2; i++)
    {
        e[s[i][0]-'a'][s[i][1]-'a']=0;
    }

    for (int i=0; i<3;i++)
    {
        memset(v, 0, sizeof(v));
        v[i]= true;
        cycle[0] = i+'a';
        if (go(i, 0))
        {
            cout << "YES\n";
            for (int i=0; i<n; i++)
            {
                cout << cycle;
            }
            cout <<"\n";
            return 0;
        };
    }
    cout << "NO\n";
}