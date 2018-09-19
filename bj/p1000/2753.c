#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	if(n%4==0){
		if (n%400==0) printf("1");
		else if (n%100==0) printf("0");
		else printf("1");
	}	
	else printf("0");
	printf("\n");
}
