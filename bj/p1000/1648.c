#include <stdio.h>
#include <string.h>
int row, col, d[14*14][1<<14];

int dfs(int n, int state){
	if (n==row*col && state==0) return 1;
	if (n>=row*col) return 0;
	if (d[n][state]>=0) return d[n][state]; 
	d[n][state]=0;
	if (state&1){
	 	d[n][state]+=dfs(n+1, state>>1);
	}
	else{
		d[n][state]+=dfs(n+1, (state| (1<< (col)))>>1);
		if ( !(state&2) && n%col != col-1)  d[n][state]+= dfs(n+2, state>>2); 
	}
	return d[n][state]%=9901;
}

int main(){
	scanf("%d %d", &row, &col);
	memset(d, -1, sizeof(d));
	printf("%d\n", dfs(0, 0));
}
