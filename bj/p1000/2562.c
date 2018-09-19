#include <stdio.h>

int main(){
	int max=0, ans;
	for (int i=1; i<10; i++){
		int tmp;
		scanf("%d", &tmp);
		if (tmp>max) ans=i, max=tmp;
	}
	printf("%d\n%d\n", max, ans);
}
