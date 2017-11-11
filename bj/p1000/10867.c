#include <stdio.h>
int a[1001];
int main(){
	int n; scanf("%d", &n);
 	int tmp;
	for (int i=0; i<n; i++){
		scanf("%d", &tmp);
		if (tmp>0)  a[tmp]|=1; 
		else a[-tmp]|=2;
	}
	for (int i=1000; i>=0; i--) if (a[i]&2) printf("%d ", -i);
	for (int i=1; i<=1000; i++) if (a[i]&1) printf("%d ", i);
	printf("\n");
}
