#include <stdio.h>

char a[1000001];
int min=-(1<<30);
int main(){
	for (int i=0; i<=1000; i++) a[i*i]=1;
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		int tmp;
		scanf("%d", &tmp);
		if (tmp<0){
			if (tmp>min) min=tmp;
		}
		else{
			if((!a[tmp]) && tmp>min) min=tmp;
		}
	}
	printf("%d\n", min);
}
