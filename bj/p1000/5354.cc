#include <stdio.h>

int main(){
	int T; scanf("%d", &T);
	while(T--){

		int n; scanf("%d", &n);
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				if ( i == 0 || j == 0 || i == n-1 || j== n-1) printf("#");
				else printf("J");
			}
			printf("\n");
		}
		printf("\n");
	}
}
