#include <stdio.h>
int d[1001][1001];
int map[1001][1001];

int min(int a, int b) {
	if(a>b) return b;
	return a;
}

int main(){

	int n, m, input, max=0;
	scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%1d", &input);
			if (i==0||j==0){ 
				d[i][j]=input;
				if (input) max=max>1?max:1; 
			}
			else {
				if (input){
					d[i][j]=min(min(d[i-1][j], d[i][j-1]), d[i-1][j-1])+1;
					if (d[i][j]>max) max=d[i][j];
				}
			}
		}	
	}

	printf("%d\n", max*max);
}

