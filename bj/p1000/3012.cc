#include <iostream>

using namespace std;
char s[202];

bool isOc(char o, char c)
{
    if ((o == '(' || o=='?') && (c==')'|| c=='?')) return true;
    if ((o == '[' || o=='?') && (c==']'|| c=='?')) return true;
    if ((o == '{' || o=='?') && (c=='}'|| c=='?')) return true;
    return false;
}

int go (int l, int r)
{
    if ( l == r ) return 1;
    if ( l+1 == r) return isOc(s[l], s[r]);
    cout << l << " " << r <<"\n";

    int ret=0;

    for (int i=l+1; i<=r; i++)
    {
        cout << l << " " << i << " " << i+1 << " " << r-1 <<"\n";
        if ( isOc(s[l+1], s[i]) && isOc(s[i+1], s[r-1])) 
        {
            ret += go(l, i)*go(i+1, r);
        }
    }

    return ret;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int n;
    cin >> n >> s;

    int ret = go(0, n-1);
    cout << ret <<"\n";
}