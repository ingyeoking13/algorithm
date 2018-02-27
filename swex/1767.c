#include <stdio.h>

int a[12][12], b[144];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int n, ans, m, max;

void go(int now, int cnt, int len){

	if ( max < cnt ) ans=len, max=cnt;
	else if ( max == cnt && ans > len ) ans=len;

	if ( now==m ) return; 

	if ( b[now]/n == 0  || b[now]%n == 0) go(now+1, cnt+1, len);
	else{
		for (int i=0; i<4;i++){
			int chk=1, tmplen=0;
			int x= b[now]/n, y=b[now]%n;
			int nx = x+dx[i], ny = y+dy[i];

			while(0<=nx && nx < n && 0<= ny && ny<n){
				if ( a[nx][ny] == 0){
					a[nx][ny]=-1;
					tmplen++;
					nx=nx+dx[i], ny=ny+dy[i];
				}
				else { chk=0; break; }
			}

			if (chk) go(now+1, cnt+1, len+tmplen);

			nx=nx-dx[i], ny=ny-dy[i];
			while(0<=nx && nx<n && 0<=ny && ny<n){
				if ( a[nx][ny] == -1 ){
					a[nx][ny]=0;
					nx=nx-dx[i], ny=ny-dy[i];
				}
				else break; 
			}
		}
		go(now+1, cnt, len);
	}
}	

int main(){

	int T; scanf("%d", &T);
	for (int t=1; t<=T; t++){
		ans= 1<<30;
		scanf("%d", &n);

		m=0, max=0;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				scanf("%d", &a[i][j]);
				if ( a[i][j] ) b[m++]=i*n+j;
			}
		}
		go(0, 0, 0);

		printf("#%d %d\n", t, ans);
	}
}
