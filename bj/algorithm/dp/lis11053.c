#include <stdio.h>

int a[1000], d[1000]={1};
int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	for (int i=1; i<n; i++){
		d[i]=1;
		for (int j=0; j<i; j++){
			if(a[j]<a[i] && d[j]+1>d[i])
					d[i]=d[j]+1;
		}
	}

	int ans=0;
	for (int i=0; i<n; i++) ans=ans<d[i]?d[i]:ans;
	printf("%d\n", ans); 
}

