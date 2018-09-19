#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int a, b, ans=1;
		scanf("%d %d", &a, &b);
		int n=b-a;
		if(!n) ans=0;
		else if (n==1) ans=1;
		else{
			int i;
			for (i=2; n-i*i>0;i++) ans+=2;
			n-=(i-1)*(i-1);
			if (n>(i-1)) ans+=2;
			else ans+=1;
		}
		printf("%d\n", ans);
	}
}
