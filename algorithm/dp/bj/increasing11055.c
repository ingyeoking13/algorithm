#include <stdio.h>

int in[1001];
int d[1001];
int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &in[i]);

	d[0]=in[0];
	for (int i=1; i<n; i++){
		d[i]=in[i];
		for (int j=0; j<i; j++){
			if(in[j]<in[i])
			 if(d[i]<d[j]+in[i])	
				 d[i]=d[j]+in[i];
		}
	}
	int ans=0;
	for (int i=0; i<n; i++){
		if (ans<d[i]) ans=d[i];
	}
	printf("%d\n", ans);
	return 0;
}
