#include <iostream>

using namespace std;
char s[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n >> s;

    int ans = 0;
    for (int i=0; i<n; i++)
    {
        ans += (s[i]-'A'+1);
    }
    cout << ans <<"\n";
}