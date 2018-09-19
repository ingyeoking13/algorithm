#include <stdio.h>

int main(){
	int now=0, ans=0;
	for (int i=0; i<4; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		now=now-a>=0?now-a:0;
		now=now+b<=10000?now+b:10000;
		ans=ans<now?now:ans;
	}
	printf("%d\n", ans);
}
