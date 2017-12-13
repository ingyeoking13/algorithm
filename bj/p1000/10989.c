#include <stdio.h>
#include <stdlib.h>

int a[10001];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) {
		int tmp; scanf("%d", &tmp);
		a[tmp]++;
	}
	for (int i=0; i<=10000; i++)
		while(a[i]--) printf("%d\n", i);
}
