#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    string str;
    cin >> str; 
    
    int j =0;
    for (int i=0; i<str.size(); i++ ) 
    {
        if ('0' <=str[i] && str[i]<='9' ) 
        {
            j=i;
            break;
        }
    }
    if( j == 0) 
    {
        cout << "error\n";
        return 0;
    }
    
    string ans;
    for (int i=0; i<str.size(); i++ )
    {
        if ('A'<= str [i]  &&  str[i] <= 'Z')  
        {
            string newElem;
            newElem += str[i];
            if ( i+1 < str.size() && 'a'<= str[i+1] &&  str[i+1] <='z') newElem += str[++i];
            
            if( j >= str.size()) { cout << "error\n"; return 0; }

            int cnt = str[j] -'0';
            if (  1<= cnt && cnt <=9) j++;
            else  { cout << "error\n"; return 0; }
            
            if ( str[j] == '0' && cnt == 1) cnt*=10;
            else if( str[j] == '0')  { cout << "error\n"; return 0; }
            
            ans += newElem;
            if ( cnt >=2) ans += to_string(cnt);
        }
        else break;
    }
    cout << ans << "\n";
    return 0;
}
