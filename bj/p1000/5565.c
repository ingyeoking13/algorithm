#include <stdio.h>

int main(){

	int ans; scanf("%d", &ans);
	for (int i=0; i<9; i++) {
		int tmp; scanf("%d", &tmp);
		ans-=tmp;
	}
	printf("%d\n",ans);
}
