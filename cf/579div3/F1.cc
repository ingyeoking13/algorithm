#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> a;
bool c[101][60001];

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n , r;
    cin >> n >> r;
    for (int i=0; i<n; i++)
    {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        a.push_back(tmp);
    }

    bool fine = true;
    for (int i=0; i<n; i++)
    {

    }

    if ( fine) cout <<"YES\n";
    else cout <<"NO\n";
}