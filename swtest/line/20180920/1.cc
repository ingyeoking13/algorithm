#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int ans= 2e4;
    bool chk=1;
	  
    for (int distance; !(ss >> distance).fail() && chk; ) {
        // @todo Write your code here.
        int tmp=0;
        distance-=40;
        tmp = 720;
        if ( ans -tmp <0 )
        {
            break;
        }
        ans -= tmp;
        while (distance >0)
        {
            if (ans >=80) 
            {
                distance -= 8;
                ans-= 80;
            }
            else 
            {
                chk=false;
                break;
            }
        }
    }
    // @todo Write your code here.
    cout << ans << endl;
    return 0;
}
