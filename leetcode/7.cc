class Solution {
public:
    int reverse(int x) {

        long long reversed = 0;
        int sign = (x<0?-1:1);
        long long temp = x;

        if (temp<0) temp *= -1;
        while(temp){
            reversed *= 10;
            reversed += temp%10;
            temp/=10;
        }
        reversed *= sign;

        if (reversed > 1LL<<31 || reversed < -1*(1LL<<31) ){
            return 0;
        }
        return reversed;
        
    }
};