#include <stdio.h>

int main(){

	int n; scanf("%d", &n);

	if ( n <6) printf("-1\n");
	else{
		if ( n==6){
			printf("1 2\n2 3\n2 4\n4 5\n4 6\n");
		}
		else if (n==7){
			printf("1 2\n2 3\n2 4\n2 5\n4 6\n4 7\n");
		}
		else{
			printf("1 2\n1 3\n2 5\n2 4\n3 6\n");
			for (int i=7; i<=n; i++) printf("4 %d\n", i);
		}
	}
	for (int i=1; i<n; i++){
		if ( i ==1 || i== 2) printf("%d %d\n", 1, i+1);
		else printf("2 %d\n", i+1);
	}
}
