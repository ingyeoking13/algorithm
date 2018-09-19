#include <stdio.h>
int a[1<<20];
int main(){
	int n;	
	while(~scanf("%d", &n)){
		if (a[n/32] & 1<<(n%32)) continue;
		else { 
			a[n/32]+=1<<(n%32);
			printf("%d ", n);
		}
	}
}
