#include <algorithm>
#include <iostream>
using namespace std;

using ll = long long;

ll gcd (ll x, ll y)
{
    return y?gcd(y, x%y):x;
}

int main() 
{
    int w, h;
    cin >> w >> h;
    ll g = gcd((ll)w, (ll)h);
    ll mw = w/g, mh = h/g;
    ll mx = max(mw, mh);
    ll mn = min(mw, mh);
    
    ll cnt = 0;
    int prevint = 0;
    double state = 0;
    double step = ((double)mn)/mx;
    
    for (int i=1; i<=mx; i++)
    {
        state += step;
        int tmp = state;
        
        if( tmp == prevint) cnt++;
        else cnt+=2;
        
        cout << tmp << " " << prevint << " " << state <<"\n";
        cout << i << " " << cnt << "\n";
        prevint = tmp;
    }
    cnt--;
    cout << mx << "\n";
    cout << cnt << "\n";
    
    cnt *= (h/mh);
    ll area = ((ll)w)*h;
    area-= cnt;
    ll answer = area;
    
	return answer;
}