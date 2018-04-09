#include <stdio.h>

int main(){

	while(1){
		int n; scanf("%d", &n);
		if ( n<0 ) break; 


		int sum=0;
		for (int i=1; i<n; i++){
			if ( n%i == 0 ) sum+=i;
		}

		if (sum == n) {
			printf("%d =", n);
			for (int i=1; i<n; i++){
				if ( n%i == 0) {
					sum-=i;
					if (sum) printf(" %d +", i);
					else printf(" %d\n", i);
				}
			}
		}
		else printf("%d is NOT perfect.\n", n);
	}
}
