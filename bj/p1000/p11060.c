#include <stdio.h>

int a[1001], d[1001];
int min(int a, int b){
	if (a<b) return a;
	return b;
}

int main(){

	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<n; i++) d[i]=100000;

	d[0]=0;
	for (int i=1; i<n; i++){
		for (int j=0; j<i; j++){
			if (i-j<=a[j]) d[i]=min(d[j]+1,d[i]);
		}
	}

	printf("%d\n", d[n-1]==100000?-1:d[n-1]);
}
