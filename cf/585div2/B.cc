#include <iostream>

using namespace std;

int a[(int)2e5];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin >> n ;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    long long ansP =0;
    int cnt1 =0, cnt2 =0;
    int bal = 0;

    for (int i=0; i<n; i++)
    {
        if ( bal % 2 == 0) cnt1++;
        else cnt2++;

        if (a[i] <0) bal++;

        if ( bal%2 == 0) 
            ansP += cnt1;
        else  
            ansP += cnt2;
    }

    cout << ((long long)n)*(n+1)/2 - ansP << " " << ansP <<"\n";
}