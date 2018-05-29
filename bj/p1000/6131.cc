#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	int ans=0;

	for (int i=1; i<=500; i++){
		for (int j=1; j<=i; j++){
			if (i*i==j*j+n) ans++;
		}
	}
	printf("%d\n", ans);
}

