#include <stdio.h>

typedef struct{int min, max; }mm;

mm func(int n){
	int t=1;
	mm ret= {0, 0};
	while(n){
		int now = n%10;
		if (now == 6 || now == 5){
			ret.min+=5*t; ret.max+=6*t;
		}
		else ret.min+=now*t, ret.max+=now*t;
		t*=10; n/=10;
	}

	return ret;
}

int main(){
	int a, b; scanf("%d %d", &a, &b);

	int max=0, min=2e6;
	printf("%d %d\n", 
			func(a).min+func(b).min, func(a).max+func(b).max);
}
