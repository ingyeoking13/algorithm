#include <stdio.h>

int a[1000001];
int main(){

	int now=1;
	while(1){
		int tmp=now, n=0;
		while(tmp){
			n+=tmp%10;
			tmp/=10;
		}
		if (now+n>1000000) break;
		if (!a[now+n]) a[now+n]=now;
		now++;
	}
	scanf("%d", &now);
	printf("%d\n", a[now]);
}
