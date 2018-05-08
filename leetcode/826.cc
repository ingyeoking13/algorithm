class Solution {
	public:
	int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
		vector<int> newp;
		newp.resize(10001);

		for (int i=0; i<d.size(); i++) newp[d[i]] = max(p[i], newp[d[i]]);
		for (int i=1; i<=10000; i++ ) newp[i] = max(newp[i], newp[i-1]);

		int ans=0;
		for (int i=0; i< w.size(); i++) ans+= newp[w[i]];
		return ans;
	}
};
