#include <stdio.h>
#include <string.h>

int d[300][300], q[90000];
int dx[8]={-1, -2, -2, -1, 1, 2, 2, 1},
		dy[8]={-2, -1, 1, 2, 2, 1, -1, -2}; 
int main(){

	int T; scanf("%d", &T);
	while(T--){
		int s, obj, n, tmp;
		scanf("%d", &n);
		scanf("%d", &tmp); s=tmp*n; scanf("%d", &tmp); s+=tmp;
		scanf("%d", &tmp); obj=tmp*n; scanf("%d", &tmp); obj+=tmp;
		memset(d, 0, sizeof(d));
		memset(q, 0, sizeof(q));
		int h=0, t=0;
		q[t++]=s; d[s/n][s%n]=1;
		while(h<t){
			int now=q[h++];
			int x=now/n, y=now%n;
			for (int i=0; i<8; i++){
				int nx=x+dx[i], ny= y+dy[i];
				if (nx>=0 && ny>=0 && nx<n && ny<n){
					if (!d[nx][ny]) {
						q[t++]=nx*n+ny; 
						d[nx][ny]=d[x][y]+1;
					}
				}
			}
		}
		printf("%d\n", d[obj/n][obj%n]-1);
	}
}
