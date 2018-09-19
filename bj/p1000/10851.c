#include <stdio.h>

char a[10000001];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		int tmp; scanf("%d", &tmp);
		if (tmp>=0) a[tmp]|=1;
		else a[-tmp]|=2;
	}
	scanf("%d", &n);
	while(n--){
		int tmp; scanf("%d", &tmp);
		if (tmp>=0) printf(a[tmp]&1?"1 ":"0 ");
		else printf(a[-tmp]&2?"1 ":"0 ");
	}
	printf("\n");
}
