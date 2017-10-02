#include <stdio.h>

int d[11]={1, 1, 2};
int main(){
	
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		for (int i=3; i<=n; i++)
			d[i]= d[i-1]+d[i-2]+d[i-3];

		printf("%d\n", d[n]);
	}
}
