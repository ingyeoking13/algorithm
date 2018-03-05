#include <stdio.h>

int main(){
	int n, k; scanf("%d %d", &n, &k);

	int cnt=0;
	for (int i=1; i<=n; i++){
		if ( n%i == 0 ){
			cnt++;
			if ( cnt == k) return !printf("%d\n", i);
		}
	}
	printf("0");
}
