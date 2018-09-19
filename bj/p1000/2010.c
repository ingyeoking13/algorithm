#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	int ans=0;
	for (int i=0; i<n; i++){
		int tmp;
		scanf("%d", &tmp);
		ans+=tmp-1;
	}
	ans++;
	printf("%d\n", ans);

}
