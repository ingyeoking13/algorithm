#include <stdio.h>

int a[46], b[1001];
int main(){

	for (int i=1; i<46; i++) a[i]+=a[i-1]+i;

	for (int i=1; i<46; i++){
		for (int j=1; j<46; j++){
			for (int k=1; k<46; k++){
				if (a[i]+a[j]+a[k]<=1000) b[a[i]+a[j]+a[k]]=1;
			}
		}
	}

	int n; scanf("%d", &n);
	while (n--){
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n", b[tmp]);
	}
}
