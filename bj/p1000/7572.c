#include <stdio.h>

char a[11]="0123456789";
char b[13]="ABCDEFGHIJKL";
int main(){
	int n; scanf("%d", &n);
	n+=56;
	n%=60;
	printf("%c%c\n",b[n%12], a[n%10]);

}
