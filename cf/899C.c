#include <stdio.h>

int a[60001];
int main(){
	int n; scanf("%d", &n);
	int remain, cnt=0; 

	if ((long long)n*(n+1)/2%2) printf("%d\n", 1);
	else printf("0\n"); 

	remain= (long long)n*(n+1)/2/2;
	for (int i=n;remain;i--){
		if (remain>=i) remain-=i, cnt++, a[i]=1;
	}
	
	printf("%d ", cnt);
	for (int i=1; i<60001; i++) if(a[i]) printf("%d ", i);
	printf("\n");
}
