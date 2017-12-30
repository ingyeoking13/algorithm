#include<stdio.h>

int main(){
	int n; scanf("%d",&n);

	while(n/10){
		int tmp=n, ans=0;
		while (tmp){
			ans+=tmp%10;
			tmp/=10;
		}
		n=ans;
		printf("%d\n", ans);
	}
	return 0;
}
