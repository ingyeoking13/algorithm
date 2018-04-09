class Solution {
	public:
  double dfs(int x, int y, int c){
		if ( x+y > c) return 0;
		if ( x+y == c) return 1;

		double ret=0; 
		ret+= (dfs(x+100, y)*0.25);
		ret+= (dfs(x+75, y+25)*0.25);
		ret+= (dfs(x+50, y+50)*0.25);
		ret+= (dfs(x+50, y+50)*0.25);
		return ret;

	}
	double soupServings(int N) {

		printf("%0.3lf\n", dfs(0, 0, N));
	}
};
