#include <iostream>
#include <random>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;
vector<int> ans, v;
int main()
{
    std::mt19937_64 eng(random_device{}());
    int n;
    n = 10;

    for (int i=1; i<=n; i++) v.push_back(i);

    int num = n;
    for (int k=0; k<num; k++)
    {
        cout << k << " ";
        std::uniform_int_distribution<int> dist(0,n-1);
        int i= dist(eng);
        cout << i << " \n";
        ans.push_back(v[i]);
        v.erase(v.begin()+i, v.begin()+i+1);
        n--;
    }

    for (int a : ans )
        cout << a << " " ;
    cout << "\n";
}