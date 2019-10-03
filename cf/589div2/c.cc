#include <iostream>
#include <vector>

using namespace std;

bool np[(int)1e5+1];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long x, n;
    cin >> x >> n;

    np[1] = true;
    for (int i=2;i<=(int)1e5; i++)
    {
        if ( np[i] == true ) continue;
        for (int j= i+i; j<=(int)1e5; j+=i)
            np[j] =true;
    }

    vector<int> dp;
    for (int i=2; i<=(int)1e5; i++)
    {
        if ( np[ i ] == false &&  x%i == 0) dp.push_back(i);  
    }
    

}