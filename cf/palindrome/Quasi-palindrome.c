// Educational Codeforces Round 29
#include <stdio.h>

int n, a[15];
int main(){

	scanf("%d", &n);
	while(!(n%10)){
		n/=10;
	}

	int t=0;
	while(n){
		a[t++]=n%10;
		n/=10;
	}

	int chk=1;
	for (int i=0; i<t/2; i++){
		if (a[t-i-1] != a[i] ) chk=0;
	}
	if(chk) printf("YES\n");
	else printf("NO\n");
}
