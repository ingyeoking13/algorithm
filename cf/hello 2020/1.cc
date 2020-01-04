#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> vs, vs2;
vector<pair<int,int>> p;
int gcd(int x, int y)
{
    return y?gcd(y,x%y):x;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;


    while(n--) 
    {
        string tmp;
        cin >> tmp;
        vs.push_back(tmp);
    }
    while(m--) 
    {
        string tmp;
        cin >> tmp;
        vs2.push_back(tmp);
    }

    n = vs.size();
    m = vs2.size();
    int g =  gcd(n, m);
    g = (n*m)/g;

    for(int i=0; i<g;i++)
        p.push_back({i%n, i%m});

    int q;
    cin >> q;

    while(q--)
    {
        int tmp;
        cin >> tmp;
        tmp--;
        cout<< vs[p[tmp%g].first] << vs2[p[tmp%g].second] <<"\n";
    }
}