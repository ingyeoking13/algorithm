#include <stdio.h>

int main(){

	int input, n, rem, i;
	scanf("%d", &input);

	for(i=input/5;i>=0;i--){
		n=i;
		rem=input-i*5;

		if (rem%3==0){
			n+=rem/3;
			rem=0;
			break;
		}
	}


	if (!rem) printf("%d\n", n);
	else printf("-1\n");
	return 0;

}
