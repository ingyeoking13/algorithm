#include <iostream>

using namespace std;
int d[31];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    d[0]=1;
    d[2] = 3;

    for (int i=4; i<=30 ; i+=2)
    {
        d[i] = 3*d[i-2]; 

        for (int j=i-4; j>=0; j-=2)
        {
            d[i] += d[j]*2;
        }
    }

    int n;
    cin >> n;
    cout << d[n] << "\n";
}