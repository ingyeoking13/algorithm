class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n= nums.size();

        for (int i=0; i<n; i++){
            
            int l =i+1, r = n-1;
 
            while(l < r){

                if ( nums[l] + nums[r] == -nums[i]) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    
                    int nextr = r-1, nextl = l+1;
                    while (nums[r] == nums[nextr]) nextr--;
                    while (nums[l] == nums[nextl]) nextl++;
                    r = nextr, l = nextl;
                }
                else if ( nums[l] + nums[r] < -nums[i]) {
                    int nextl = l+1;
                    while (nextl < r && nums[l] == nums[nextl]) nextl++;
                    l=nextl;
                }
                else{
                    int nextr = r-1;
                    while (nextr > l && nums[r] == nums[nextr]) nextr--;
                    r = nextr;
                }
            }
            
            while ( nums[i] == nums[i+1]) i++;
        
        }
        return ans;
    }
};