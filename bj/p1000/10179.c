#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	while(n--){
		double tmp; scanf("%lf", &tmp);
		printf("$%0.2lf\n", tmp*0.8);
	}
}
