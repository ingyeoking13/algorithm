#include <iostream>
#include <vector>

using namespace std;
int p[21], h[21];
vector<int> v[21];

void go(int i, int depth)
{
    h[i] = depth;
    for (int j=0; j<v[i].size(); j++)
    {
        go( v[i][ j ] , depth+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin >> n;

    int root;
    for (int i =1; i<=n; i++)
    {
        cin >> p[i];
        if ( p[i] == -1)
        {
            root = i;
        }
    }

    for (int i =1; i<=n; i++)
    {
        if ( p[i] == -1) continue;
        v[ p[i] ].push_back(i);
    }

    go ( root, 0 );
    if ( v[0].size() >0 ) 
    {
        for (int i=0; i<v[0].size(); i++) go( v[0][i], 0 );
    }
    for (int i=1; i<=n; i++)
    {
        cout << h[i] <<"\n";
    }
}