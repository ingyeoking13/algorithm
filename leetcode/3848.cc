class Solution {
public:
    int fac[10] = {1,};
    int a[10] = {0,};
    bool isDigitorialPermutation(int n) {
        initFac(n);
        int target = getFac(n);
        int result = goFac(a, target, 0, 0, lenn(n));
        if (result) {
            return true;
        }
        return false;
    }

    int initFac(int n) {
        fac[1]=1;
        for (int i=2; i<10; i++) {
            fac[i] = i*fac[i-1];
        }
        while (n) {
            a[n%10]++;
            n/=10;
        }
        return 0;
    }

    int getFac(int n){
        int result = 0;
        while(n){
            int val = n % 10;
            result += fac[val];
            n/=10;
        }
        return result;
    }

    int lenn(int n) {
        int result = 0;
        while (n) {
            result++;
            n/=10;
        }
        return result;
    }

    int goFac(int* a, int &target, long long val, int depth, int len) {
        if (depth == len) {
            return val == target;
        }

        for (int i=0; i<10; i++) {
            if (a[i] == 0) continue;
            if (depth == 0 && i == 0) continue;
            val *= 10;
            val += i;
            a[i]--;
            if (goFac(a, target, val, depth+1, len)) {
                return 1;
            }
            val -= i;
            val /= 10;
            a[i]++;
        }
        return 0;
    }
    
};