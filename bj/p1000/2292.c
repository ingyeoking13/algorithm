#include <stdio.h>

int main(){
	int n; scanf("%d", &n);

	int an=1, ans=0; 
	for (int i=0;; i++){
		an+=6*i;
		if (n<=an) { ans=i; break;}
	}
	printf("%d\n", ans+1);
}
