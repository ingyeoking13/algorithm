#include <stdio.h>

int v[101];
int main(){

	int n; scanf("%d", &n);
	int tmp;
	while(n--){
		scanf("%d", &tmp);
		if (tmp<0) {
			tmp=-tmp;
			v[tmp]+= 1<<10;
		}
		else v[tmp]++;
	}
	scanf("%d", &tmp);
	if (tmp<0){
	 	tmp=-tmp;
		printf("%d\n", (v[tmp]>>10));
	}
	else{
		v[tmp]%=(1<<10);
	 	printf("%d\n", v[tmp]);
	}
}
