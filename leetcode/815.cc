class Solution {
public:
	vector<int> e[501];
	map<int, int> m;
	int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
		for (int i=0; i<routes.size(); i++){
			for (int j=0; j<routes[i].size(); j++){
				if ( m[routes[i][j]] == map.end()) m[routes[i][j]] = m.size();
			}
		}

		for (int i=0; i<routes.size(); i++){
			for (int j=0; j<routes[i].size(); j++){
				printf("m[%d] : %d\n", routes[i][j],m[routes[i][j]]);
			}
		}
			
	}
};
