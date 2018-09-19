#include <stdio.h>
int main(){
	int n; scanf("%d", &n);
	int ans=0;
	while(n){
		if(n%2) ans++;
		n/=2;
	}
	printf("%d\n", ans);
}
