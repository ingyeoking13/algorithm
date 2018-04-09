#include <stdio.h>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& f, vector<int>& nums) {

			vector<int> pos; pos.resize(100000);
			vector<int> ans;
			for (int i=0; i<nums.size(); i++) pos[nums[i]]=i;

			for (int i=0; i<f.size(); i++){

				int ret = -1;
				for (int j=pos[f[i]]; j<nums.size(); j++){
					if ( f[i] < nums[j] ){
					 	ret = nums[j];
						break;
					}
				}
				ans.push_back(ret);
			}
			return ans;
    }

};
