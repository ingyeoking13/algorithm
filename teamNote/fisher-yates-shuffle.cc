#include <iostream>
#include <random>
#include <vector>
using namespace std;

vector<int> v, ans;
int main()
{
    int n = (int)2e7;
    for (int i=1; i<=n; i++)
        v.push_back(i);
    
    mt19937_64 eng(random_device{}());

    int m = n;
    for (int i=0; i<n; i++)
    {
        uniform_int_distribution<> dist(0, m-1);
        int j = dist(eng);
        ans.push_back(v[j]);
        v.erase(v.begin()+j, v.begin()+j+1);
        m--;
    }

    for (int i : ans)
        cout << i << " ";
    cout << "\n";
}