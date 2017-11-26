#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	int i=1;
	while(1){
		if (n==1) break;
		else{
			if (n%2) n=n*3+1;
			else n/=2;
		}
		i++;
	}
	printf("%d\n", i);
}
