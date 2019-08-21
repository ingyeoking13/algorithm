#include <iostream>
#include <vector>

using namespace std;

vector<int> rep;
vector<bool> chk;
vector<vector<int>> ans;

void go(int now, vector<int> a, int depth)
{
    if ( depth == 6)
    {
        int sum = 0;
        for( auto i : a)
        {
            sum += i;
        }

        bool chk =false;
        for (int i=0; i<4; i++)
        {
            if (a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] ) 
            {
                chk = true;
            }
        }

        if ( sum >= 110 && sum <= 190 && !chk) ans.push_back(a);
        return;
    }

    for (int i = now+1; i<=45; i++)
    {
        a.push_back(i);
        go(i, a, depth+1);
        a.pop_back();
    }
};

int main()
{
    for (int i=1; i<=45; i++) rep.push_back(i);
    chk.resize(46, false);

    vector<int> a;
    go(0, a, 0);

    for( auto v : ans )
    {
        for ( auto i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}
