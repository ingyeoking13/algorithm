#include <stdio.h>
#include <string.h>

int a[101];
int main(){

	for (int i=1; i<=10; i++){
		memset(a, 0, sizeof(a));
		int max=0;

		for (int j=0; j<1000; j++){
			int tmp; scanf("%d", &tmp);
			a[tmp]++;
		}

		for (int j=0; j<=100; j++) {
			printf("%d %d\n", j, a[j]);

		}

		int ans=0;
		for (int j=0; j<=100; j++){
			if (max<a[j]) {
				max=a[j]; ans=j;
			}
			else if (max==a[j]) 
				if (ans<j) ans=j;
		}

		printf("#%d %d %d %d\n", i, ans, a[77], a[79]);
	}
}
