#include <stdio.h>

int main(){

	int ans=0;
	int n; scanf("%d", &n);
	for (int i=0; i<5; i++){
		int tmp;
	 	scanf("%d", &tmp);
		if (tmp==n) ans++;
	}
	printf("%d\n", ans);
}
