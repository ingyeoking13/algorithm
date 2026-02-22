class Solution {
public:
    int binaryGap(int n) {
        int i=-1; 
        int j=-1;
        int k=0;
        int ans = 0;
        while (n) {
            int cur = n%2;
            if (cur == 0) {
                k++;
                n/=2;
                continue;
            }
            if (i>=0 && j>=0) {
                i = j;
                j = k++;
            }
            else if (i>=0) {
                j = k++;
            } else {
                i = k++;
            }

            if (i >=0 && j >=0) {
                // cout << i << " " << j << "\n";
                ans = max(ans, j-i);
            }
            n/=2;
        }

        return ans;
    }
};