class Solution {
public:
    int myAtoi(string s) {
        int l = s.size();
        long long number = 0;
        int sign = 0;
        char hit = 0;

        for (int i=0; i<l; i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                hit = 1;
                number *= 10;
                number += (c - '0');

                if ((sign*number) < -(1LL<<31))  {
                    number = 1LL<<31;
                    break;
                } else if ( (sign == 0 || sign == 1) && number >= (1LL<<31)-1) {
                    cout << number;
                    number = (1LL<<31)-1;
                    break;
                }

            } else if (c =='-' )  {
                if (hit) break;

                if (sign == 0)  sign = -1;
                else break;
            }
            else if (c == '+' ) {
                if (hit) break;

                if (sign == 0) sign = 1;
                else break;
            }
            else if (c == ' ') {
                if (sign) break;
                if (hit) break;
            }
            else break;
        }

        if (sign == 0) sign =1;

        number *= sign;
        return number;

    }
};