class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int p[2] = {0, 0};
        int cur = 0;

        for (unsigned int i=0; i<nums.size(); i++) {
            if (nums[i]%2) {
                cur += 1;
                cur %= 2;
            }
            if (i%6 == 5) {
                cur += 1;
                cur %= 2;
            }
            p[cur] += nums[i];
        }

        return p[0] - p[1];
        
    }
};