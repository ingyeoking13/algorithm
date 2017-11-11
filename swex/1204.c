#include <stdio.h>

int a[101];
int main(){

	for (int i=1; i<=10; i++){
		for (int j=0; j<101; j++) a[j]=0;

		int tmp, max=0;
		scanf("%d", tmp);
		for (int j=0; j<1000; j++){
			scanf("%d", &tmp);
			a[tmp]++;
		}

		int ans=0;
		for (int j=0; j<101; j++){
			if (a[ans]<=a[j])  ans=j; 
		}

		printf("#%d %d\n", i, ans);
	}
}
