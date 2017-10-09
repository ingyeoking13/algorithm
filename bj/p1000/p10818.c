#include <stdio.h>

int main(){
	int n, tmp, max=0, min=1000000;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &tmp);
		if (tmp>max) max=tmp;
		if (tmp<min) min=tmp;
	}
	printf("%d %d\n", min, max);
}
