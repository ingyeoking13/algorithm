#include <iostream>
#include <random>
#include <vector>
using namespace std;

vector<int> v, ans;
int main()
{
    int n = (int)2e5;
    for (int i=1; i<=n; i++)
        v.push_back(i);
    
    mt19937_64 eng(random_device{}());

    for (int i=n-1; i>0; i--)
    {
        uniform_int_distribution<> dist(0, i-1);

        int j = dist(eng);

        int tmp = v[j];
        v[ j ] = v[ i ];
        v[ i ]  = tmp;
    }

    for (int i : v)
        cout << i << " ";
    cout << "\n";
}