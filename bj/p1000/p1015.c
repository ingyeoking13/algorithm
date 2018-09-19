#include <stdio.h>
#include <stdlib.h>

int a[51], b[51], p[51];
int mycmp(const void* a, const void* b){
	int ret= *(int *)a - *(int *)b;
	return ret?ret:-1;
}
int main(){

	int n, tail=0;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
		b[i]=a[i];
	}
	qsort(b, n, sizeof(int), mycmp);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if(a[i]==b[j]) {
				p[tail++]=j;
				b[j]=1<<30;
				break;
			}
		}
	}
	for (int i=0; i<n; i++) printf("%d ", p[i]);
	printf("\n");
}
