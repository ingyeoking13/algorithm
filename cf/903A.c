#include <stdio.h>

int main(){

	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d", &n);
		int chk=0;
		for (int big= n/7; big>=0; big--){
			int remain = n-big*7;
			if (remain%3==0) chk=1;
		}
		printf(chk?"YES\n":"NO\n");
	}
}
