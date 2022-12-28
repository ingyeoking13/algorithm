class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;

        while (l < r) {
            int width = r - l;
            ans = max(ans, min(height[l], height[r])* width);
            if ( height[l] <= height[r] ) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
