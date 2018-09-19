class Solution {
	public:
		vector<int> findDiagonalOrder(vector<vector<int>>& m) {

			vector<int> ans;
			int row = m.size();
			if ( !row )  return ans;

			int col = m[0].size();

			int mx = max(row, col);
			for (int k=0; k<row+col; k++){

				if ( k & 1){
					for (int i=0; i<row; i++){
						for (int j=0; j<col; j++){
							if( j+i == k) printf("%d ", m[i][j]);
						}
				}
				else {
					for (int i=row-1; i>=0; i--){
						for (int j=0; j<col; j++){
							if( j+i == k) printf("%d ", m[i][j]);
						}
					}
				}
			}
		}

	}
};
