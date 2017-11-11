#include <stdio.h>
int main(){
	int n; scanf("%d", &n);

	while(n--){
		int total; scanf("%d", &total);
		int ans, rem;
		for (int kg5=total/5; kg5>=0; kg5--){
			ans=kg5, rem=total-kg5*5;

			if (rem%3==0){
				ans+=rem/3;
				rem=0;
				break;
			}
		}

		if (rem) printf("-1\n");
		else printf("%d\n", ans);
	}
}
