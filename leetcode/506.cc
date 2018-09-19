class Solution {
	public:
		vector<string> findRelativeRanks(vector<int>& nums) {
			priority_queue<pair<int, int> > pq;
			vector<string> ans(nums.size());
			for (int i=0; i<nums.size(); i++) pq.push({nums[i], i});

			for (int i=0; i<nums.size(); i++){
				int now = pq.top().second; pq.pop();
				if ( i == 0 ) ans[now]="Gold Medal";
				else if ( i == 1) ans[now] ="Silver Medal";
				else if ( i == 2) ans[now] - "Bronze Medal";
				else ans[now]= to_string(i+1);
			}

			return ans;
							
		}
};
