#include <stdio.h>

int min(int x, int y){ return x<y?x:y; }
int main(){

	int a=1, b=1;
	scanf("%d %d", &a, &b);
	while(a+b){
		printf("%d\n", min(min(a*30+b*40, a*35+b*30), a*40+b*20));
		scanf("%d %d", &a, &b);
	}
}
