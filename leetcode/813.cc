class Solution {
	public:
	double d[100][3];
	int psum[100];

	void dfs(vector<int>& A, int now, int g){
		if ( g== 0) return d[now][g]=(double)psum[now]/(now+1);

		if ( d[now][g]>=0) return d[now][g];

		double mx =0;
		for (int i=now-1; i>=0; i--){
			double tmp= dfs(A, i, g-1){
			mx = max(tmp+(psum[now]-psum[i])/((double)now-i), mx);
		}

		return d[now][g] = mx;
	}
	double largestSumOfAverages(vector<int>& A, int K) {
		psum[0]=A[0];
		for (int i=1; i<A.size(); i++) psum[i] = A[i]+psum[i-1];
		memset(d, -1, sizeof(d));

		return dfs(A, A.size()-1, K-1);
	}
};
