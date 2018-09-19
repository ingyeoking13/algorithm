#include <stdio.h>

int main(){

	int sum=0, min=101;
	for (int i=0; i<7; i++){
		int tmp;
	 	scanf("%d", &tmp);

		if (tmp&1) {
			sum+=tmp;
			min=min>tmp?tmp:min;
		}
	}
	if (sum) printf("%d\n%d\n", sum, min);
	else printf("-1\n");

}
