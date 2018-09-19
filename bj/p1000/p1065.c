#include <stdio.h>

int han(int num){
	int chk=1;
	int d = num%10-num/10%10;
	num/=10;
	while (num/10) {
		if ((num%10-num/10%10)!=d) chk=0;
		num/=10;
	}
	if (chk) return 1;
	return 0;
}

int main(){
	int n, ans=0;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) ans+=han(i); 

	printf("%d\n", ans);
}
