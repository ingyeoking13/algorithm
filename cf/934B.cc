#include <bits/stdc++.h>

int main(){
	int k; scanf("%d", &k);
	if (k<=36){
		for (int i=k; i>0; i--){
			if ( i>1 ){
				printf("8");
				i--;
			}
			else printf("9");
		}
	} else printf("-1");
	printf("\n");
}
