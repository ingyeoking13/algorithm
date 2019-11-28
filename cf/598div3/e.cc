#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct Node
{
    int id, val;
    Node(){};
    Node(int id, int val) : id(id), val(val) {};
    bool operator< (Node o) 
    {
        return val < o.val;
    }
};

struct edge
{
    int u, v, w;
    edge() {};
    edge(int u, int v, int w) :u(u), v(v), w(w) {};
    bool operator< (edge o) 
    {
        return w < o.w;
    }
};

Node a[(int)2e5];
int ans[(int)2e5];
int p[(int)2e5];
int main ()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        a[i].id = i;
        cin >> a[i].val;
    }

    sort(a, a+n);

    vector<edge> e;
    for (int i=2; i<n-3; i++)
    {
        e.push_back( {i, i+1, a[i+1].val - a[i].val});
    }

    sort(e.begin(), e.end());
    p[0] = p[1] = p[2] = 0;
    p[n-3] = p[n-2] = p[n-1] = n-1;

    int erase = n/3-1;
    set<int> ss;
    for (int i=0; i<erase; i++)
    {
        ss.insert(e[i].u);
    }

    int group = 1;
    for (int i=0; i<n; i++)
    {
        ans[ a[i].id ] = group; 
        if( ss.find( i ) != ss.end() )
        {
            group++;
        }
    }

    for (int i=0; i<n; i++)
    {
        cout << ans[i]  << " ";
    }
    cout << "\n";

}