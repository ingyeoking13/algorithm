#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string a, b, ans;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int up=0, i;
    for (i=0; i<a.size() && i<b.size(); i++)
    {
        int now=a[i]-'0' + b[i]-'0'+ up;
        ans.push_back(now%10+'0');
        up = now/10;
    }

    while(i<a.size())
    {
        int now = a[i]-'0' + up;
        ans.push_back(now%10+'0');
        up = now/10;
        i++;
    }
    while(i<b.size())
    {
        int now = b[i]-'0' + up;
        ans.push_back(now%10+'0');
        up = now/10;
        i++;
    }
    if (up) ans.push_back(up+'0');

    reverse(ans.begin(), ans.end());
    cout << ans;
}