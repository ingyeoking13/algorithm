class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x==0) return true;

        string s;
        while(x){
            s += (x%10) + '0';
            x/=10;
        }

        int l = s.size();
        for (int i=0; i<l/2; i++) {
            if ( s[i] != s[l-1-i] )  return false;
        }
        return true;
    }
};