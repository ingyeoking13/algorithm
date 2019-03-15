#include <stdio.h>

void swp(int *x, int *y) { int tmp = *x; *x = *y; *y = tmp; }

int main(){
	int n, a, b; scanf("%d %d %d", &n, &a, &b);
	if ( a> b) swp(&a, &b);

	int ans=1;
	while(b/2+b%2 != a/2+a%2){

		a=a/2+a%2;
		b=b/2+b%2;
		ans++;

	}

	int tmp=1;
	for (int i=0; i<ans; i++) tmp*=2;
	if ( tmp == n )  printf("Final!\n");
	else	printf("%d\n", ans);

}
