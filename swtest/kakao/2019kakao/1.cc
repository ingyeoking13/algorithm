#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int ans = s.size(); // 단위가 자기 자신일 경우 
    
    for (int len =1; len< s.size(); len++)
    {
        int pos = 0;
        int builded = 0;
        while ( pos + len <= s.size() )
        {
            string pattern;
            for (int i = pos; i< pos + len; i++)
            {
                pattern += s[i]; 
                builded ++;
            }
            
            int cnt = 1;
            bool matched= false;
            pos+=len;
            
            do 
            {
                if ( pos + len > s.size() )  break;
                
                matched = true;
                for (int i=0; i<len; i++)
                {
                    matched &= (pattern[i] == s[pos + i]);
                }
                if (matched) cnt ++;
            }while( matched && (pos+=len));
            
            if ( cnt == 1);
            else
            {
            while (cnt)
            {
                cnt /= 10;
                builded++;
            }
            }
            //cout << pos << " " << builded << "\n";
        }
        //remain
        builded += s.size()  - pos;
        ans = min(builded, ans);
        //cout <<  len << ":  " << builded <<"\n";
    }
    return ans;
}