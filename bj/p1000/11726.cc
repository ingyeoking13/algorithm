#include <iostream>

using namespace std;
int d[(int)1e3+1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    d[0] = d[1]= 1;

    for (int i =2; i<=1e3; i++)
    {
        d[i] = d[i-1];
        d[i] += d[i-2]; 
        d[i] %= ((int)1e4+7);
    }
    cout << d[n] <<"\n";
}