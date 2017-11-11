#include <stdio.h>
char a[51][51]; int ans, n;
void adkb(int now, int chk){
	int x=now/n, y=now%n; char tmp;
	if (now==n*n) return;
	if (chk && y<n-1) {tmp=a[x][y]; a[x][y]=a[x][y+1]; a[x][y+1]=tmp;} 
	else if (x<n-1) { tmp=a[x][y]; a[x][y]=a[x+1][y]; a[x+1][y]=tmp;} 

	for (int i=0; i<n; i++){
		int len=0, j=0; char peg=a[i][0]; 
		while (j<n){
			if (peg==a[i][j]) len++;
			else {
				if (ans<len) ans=len;
				len=1; peg=a[i][j];
			}
			j++;
		}
		if (ans<len) ans=len;

		peg=a[0][i], len=0, j=0;
		while (j<n){
			if(peg==a[j][i]) len++;
			else{
				if (ans<len)  ans=len; 
				len=1; peg=a[j][i];
			}
			j++;
		}
		if (ans<len) ans=len;
	}

	if (chk && y<n-1) {tmp=a[x][y]; a[x][y]=a[x][y+1]; a[x][y+1]=tmp; }
	else if (x<n-1) {tmp=a[x][y]; a[x][y]=a[x+1][y]; a[x+1][y]=tmp;} 
	adkb(now+1, chk);
}

int main(){
	scanf("%d", &n);

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			scanf(" %c", &a[i][j]);

	adkb(0, 1); adkb(0, 0);
	printf("%d\n", ans);
}
