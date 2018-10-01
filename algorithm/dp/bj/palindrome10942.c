#include <stdio.h>

int a[2001], d[2001][2001];
int main(){
	int n;
	scanf("%d", &n);

	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	// init
	for (int i=0; i<n; i++) d[i][i]=1;
	for (int i=0; i<n-1; i++) if(a[i]==a[i+1]) d[i][i+1]=1;

	for (int len=2; len<n; len++){
		for (int i=0; i<n-len;i++){
			if (a[i]==a[i+len] && d[i+1][i+len-1]) 
				d[i][i+len]=1;
		}
	}

	int T;
	scanf("%d", &T);
	while(T--){
		int a, b;
		scanf("%d %d", &a, &b);
		if (d[a-1][b-1]) printf("1\n");
		else printf("0\n");
	}
}

