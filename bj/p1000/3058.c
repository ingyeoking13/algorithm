#include <stdio.h>

int a[7];
int main(){
	int T; scanf("%d", &T);
	while(T--){
		int sum=0, min=101;
		for (int i=0; i<7; i++) {
			scanf("%d", &a[i]);
			if (( a[i] & 1) == 0){
				sum+=a[i];
				if ( min > a[i] ) min = a[i];
			}
		}
		printf("%d %d\n", sum, min);
	}
}
