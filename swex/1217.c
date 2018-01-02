#include <stdio.h>

int main(){
	for (int t=1; t<=10; t++){
		scanf("%d", &t);

		int a, b;
		scanf("%d %d", &a, &b);
		int ans=1;

		while(b--){
			ans*=a;
		}
		printf("#%d %d\n", t, ans);

	}
}
