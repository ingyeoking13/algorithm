#include <stdio.h>

int main(){
	int x, h, m;
	scanf("%d %d %d", &x, &h, &m);

	int now = h*60+m;
	int cnt = 0;
	while (1){
		if ( now<=0 ) now=60*24+now;
		if ( now%10 == 7 || now/60 == 7 || now/60 == 17) break;
		now -=x;
		cnt++;
	}

	printf("%d\n", cnt);
}
