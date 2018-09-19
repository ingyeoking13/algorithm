#include <algorithm>
#include <string.h>
using namespace std;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	int row, col;
	int chk[50][50]; 
class Solution {
public:

	int dfs(int x, int y){
		int ret =1;

		for (int i=0; i<4; i++){
			int nx = x+dx[i], ny = y+dy[i];
			if (0<= nx && nx<row && 0<= ny&& ny <col ) {
				if (chk[nx][ny]) continue;
				ret += dfs(nx, ny);
			}
		}
		return ret;
	}

	int largestIsland(vector<vector<int>>& g) {
		row =  g.size();
		if (row) col = g[0].size();
		else return 0;


		int ans=0;
		for (int i=0; i<row; i++){
			for (int j=0; j<col; j++){
				if (g[i][j] == 0) { 
					g[i][j] =1; 
					memset(chk, 0, sizeof(chk));
					int area=0;

					for (int k=0; k<row; k++){
						for (int l=0; l<col; l++){

							if ( g[k][l]==1){
								if ( chk[k][l] )  continue;
								area+= dfs(k, l);
							}
						}
					}
					ans = max(area, ans);
					g[i][j]=0;
				}
			}
		}
		return ans;
	}
};
