#include <stdio.h>

long long int min, max, i, j, ans=0;
int main(){

	scanf("%lld %lld", &min, &max);
	for (i=min; i<=max; i++){
		for (j=2; j*j<=max; j++){
			if(j*j==i) {ans++; break;}
		}
	}
	printf("%lld\n", max-min-ans+1); 
}
