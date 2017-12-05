#include <stdio.h>

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		int init=0; w=0;
		while(n>init) init+=h, w++; 
		printf("%d%02d\n", h-init+n, w);
	}
}
