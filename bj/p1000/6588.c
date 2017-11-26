#include <stdio.h>

int p[1000001]={1, 1};
int main(){

	for (int i=2; i<=1000000; i++){
		if (!p[i]){
			for (int j=i+i; j<=1000000; j+=i) p[j]=1;
		}
	}

	while(1){
		int n; scanf("%d", &n);
		int chk=0;
		if (!n) break;
		for (int i=2; i<=1000000; i++){
			if (!p[i] && i%2 && !p[n-i]){
				chk=1;
				printf("%d = %d + %d\n", n, i, n-i); break;
			}
		}
		if(!chk) printf("Goldbach's conjecture is wrong.\n");
	}
}
