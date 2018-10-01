#include <stdio.h>
int d[1001]={1, 1};

int main(){
	int num;
	scanf("%d", &num);
	for (int i=2; i<=num; i++){ d[i]=(d[i-1]%10007+d[i-2]%10007)%10007; }

	printf("%d\n", d[num]);

}

