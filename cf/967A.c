#include <stdio.h>
char a[100];
int main(){
	int n;scanf("%d", &n);
	scanf("%s", a);
	int cnt=0, cnt2=0;
	for (int i=0; i<n; i++) {
		if(a[i]=='0') cnt++;
		else cnt2++;
	}
	if ( cnt2){
	printf("1");
	for (int i=0; i<cnt; i++) printf("0");
	printf("\n");
	}
	else printf("0");
} 
