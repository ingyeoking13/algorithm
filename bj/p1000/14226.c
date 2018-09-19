#include <stdio.h>

int d[1001][1001], q[1002001], h, t;
int main(){
	int n; scanf("%d", &n); 

	d[1][0]=1;
	q[t++]=10000;

	while(h<t){
		int state = q[h++];
		int now = state/10000, c = state%10000;

		if ( now+c <= 1000) {
			if ( !d[now+c][c] ) {
				d[now+c][c] = d[now][c]+1;
				q[t++] = (now+c)*10000+c; }
		}

		if ( !d[now][now] ) {
			d[now][now] = d[now][c] +1;
			q[t++]=now*10000+now;
		}

		if ( now-1 > 0 ){
			if ( !d[now-1][c] ) {
				d[now-1][c] = d[now][c]+1;
				q[t++] =(now-1)*10000+c;
			}
		}
	}

	int ans = 100000;
	for (int i= 0; i<=1000; i++) 
		if ( d[n][i] && d[n][i] < ans ) ans = d[n][i];
	printf("%d\n",ans-1);
}
