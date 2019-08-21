#include <iostream>
#include <set>

using namespace std;

int a[100], b[100];
set<int> s;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    for (int i=0; i<n; i++) 
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    cin >> m;
    for (int i=0; i<m; i++) 
    {
        cin >> b[i];
        s.insert(b[i]);
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            int val = a[i]+b[j];
            if ( s.find(val) == s.end())
            {
                cout << a[i] << " " << b[j] << "\n";
                return 0;
            }
        }
    }

}