#include <stdio.h>

long long d[1001]={0, 1, 1}; 
int a[1001]={0, 1, 1};

int main(){
	for (int i=3; i<=1001; i++){
		d[i]= d[i-1]+d[i-2];
		if (0<=d[i] && d[i] <=1000 ) a[d[i]]=1;
	}

	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++){
		if (a[i]) printf("O");
		else printf("o");
	}
	printf("\n");
}
