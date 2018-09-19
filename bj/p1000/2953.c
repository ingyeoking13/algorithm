#include <stdio.h>

int main(){
	int max=0, ans;
	for (int i=1; i<=5; i++){
		int now=0;
		for (int j=0; j<4; j++){
			int tmp;
			scanf("%d", &tmp);
			now+=tmp;
		}
		if (now>max) max=now, ans=i;
	}
	printf("%d %d\n", ans, max);
}
