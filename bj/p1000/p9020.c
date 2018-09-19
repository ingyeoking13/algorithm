#include <stdio.h>

int p[10001]={1, 1, 0};
int main(){

	for (int i=2; i<=10001; i++){
		if (!p[i]){
			for (int j=i+i; j<=10001; j+=i){
				p[j]=1;
			}
		}
	}
	int T;
	scanf("%d", &T);

	while(T--){

		int n;
		scanf("%d", &n);
		int m=n>>1;
		int i, j;

		for (i=j=m;i<=n;)



	}
}
