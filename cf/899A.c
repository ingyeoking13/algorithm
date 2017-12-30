#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	int one=0, two=0;
	for (int i=0; i<n; i++) {
		int tmp;
		scanf("%d", &tmp); 
		if (tmp%2) one++;
		else two++;
	}
	int ans=0;
	if(one> two){
		ans+=two;
		one-=two;
		ans+=one/3;
	}
	else {
		ans=one;
	}
	printf("%d\n", ans);
}
