#include <stdio.h>

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
			vector<int> ans;
			int n = nums.size();

			for (int i=0; i<n; i++) {

				int now =(i+1)%n, chk=0;
				while( now != i ){

					if ( nums[now] > nums[i])  {
						ans.push_back(nums[now]);
						chk=1;
						break;
					}

					now= (now+1)%n;

				}
				if ( !chk ) ans.push_back(-1);
			}
			return ans;
    }
};
