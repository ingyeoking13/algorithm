#include <stdio.h>

int a[101], h, t;
int main(){
	int f, to; scanf("%d %d", &f, &to);

	for (int i=1; i<=100; i++){
		if (i*i>=f && i*i<=to) a[t++]=i*i;
	}
	if (t==0) return printf("-1\n");
	int sum=0;
	while(h<t){
		sum+=a[h++];
	}
	printf("%d\n%d\n", sum, a[0]);
}
