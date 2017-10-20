#include <stdio.h>

int d[100001][3];
int max(int a, int b){
	if (a>b) return a;
	return b;
}
int main(){

	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%d", &d[i][0]);
		for(int i=1; i<=n; i++) scanf("%d", &d[i][1]); 

		int tmp= d[1][0];
		d[1][0]=0;
		d[1][2]=d[1][1];
		d[1][1]=tmp;

		for (int i=2; i<=n; i++){
			d[i][2]=max(d[i-1][0]+d[i][1],d[i-1][1]+d[i][1]);
			d[i][1]=max(d[i-1][0]+d[i][0],d[i-1][2]+d[i][0]);
			d[i][0]= max(max(d[i-1][0],d[i-1][1]),d[i-1][2]);
		}
		int ans;
		ans=max(max(d[n][0],d[n][1]),d[n][2]);
		printf("%d\n", ans);

	}
}
