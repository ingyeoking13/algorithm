#include <stdio.h>

int d[12]={0, 1, 2, 4};
int main(){
	int T;
	scanf("%d", &T);

	for (int i=4;i<=11; i++) d[i]= d[i-1]+d[i-2]+d[i-3];

	while(T--){
		int n;
		scanf("%d",&n);
		printf("%d\n", d[n]);
	}
}
