#include <stdio.h>
#include <string.h>
char a[2501]; int d[2501];
int p[2501][2501];

int min(int x, int y) { if(x<y) return x; return y;}
int chk(int n){
	if (n<0) return d[n]=0;
	if (d[n]) return d[n];
	d[n]=n+1;
	for (int i=0; i<=n; i++){
		if (p[i][n])
			d[n]=min(chk(i-1)+1,d[n]);
	}
	return d[n];

}
int palin(int f, int t){
	if (f==t) return p[f][t]=1;
	if (p[f][t]>=0) return p[f][t];
	if (a[f]!=a[t]) return p[f][t]=0;

	if (a[f]==a[t]){
		if (f+1==t) return p[f][t]=1;
		return p[f][t]=palin(f+1, t-1);
	}
}

int main(){
	scanf("%s", a);
	int len=strlen(a);
	for (int i=0; i<len; i++)
		for (int j=0; j<len; j++)
			p[i][j]=-1;

	for (int i=0; i<len; i++){
		for (int j=len-1; j>=i; j--){
			palin(i,j);
		}
	}
	printf("%d\n", chk(len-1));
}
