#include <stdio.h>

int d[31];
int main(){
	d[0]=1;
	for (int i=1; i<31; i++) d[i]=d[i-1]*2;

	int n; scanf("%d", &n);
	for (int i=0; i<31; i++) if (d[i]==n) return !printf("1\n");
	printf("0\n");

}
