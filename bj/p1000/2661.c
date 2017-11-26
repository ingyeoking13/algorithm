#include <stdio.h>

int n, a[81];
int chka(int idx, int len){
	int chk=1;
	for (int i=idx; i<idx+len; i++){
		if (a[i]!=a[len+i]) chk=0;
	}
	return chk;
}
int chkf(int maxl){
	int chk=1;
	for (int len=1; len<=maxl/2; len++){
		for (int i=0; i<=maxl-2*len; i++){
				int sub=chka(i, len);
				if (sub) chk=0;
		}
	}
	return !chk;
}
int dfs(int i){
	if (i!=0 && chkf(i)) return 0;
	if (i==n){
		for (int j=0; j<n; j++) printf("%d", a[j]);
		printf("\n");
		return 1;
	}
	for (int j=1; j<=3; j++){
		a[i]=j;
		if(dfs(i+1)) return 1;
	}
	return 0;
}

int main(){
	scanf("%d", &n);
	dfs(0);
}
