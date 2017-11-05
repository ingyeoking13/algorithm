#include <stdio.h>

int main(){
	int a, b, v, day=1;
	scanf("%d %d %d", &a, &b, &v);
	while((v-=a)>0){
	 	v+=b;
		day++;
	}
	printf("%d\n", day);
}

