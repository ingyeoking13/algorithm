#include <stdio.h>

int main(){

	int num[21], n, obj, ans=0;
	scanf("%d %d", &n, &obj);
	for (int i=0; i<n; i++)
		scanf("%d", &num[i]);

	for (int i=1; i<(1<<n); i++){
		int sum=0;
		for (int j=0; j<n; j++){
			if(i&(1<<j)) 
				sum+=num[j];
		}
		if (sum==obj) ans++;
	}
	printf("%d\n", ans);
}
