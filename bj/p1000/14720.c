#include <stdio.h>

int st[3] ={1, 2, 0};
int main(){
	int n; scanf("%d", &n);

	int now=2, ans=0;
	for (int i=0; i<n; i++){
		int tmp;
		scanf("%d",  &tmp);

		if ( st[now] == tmp ) ans++, now=tmp;
	}
	printf("%d\n", ans);
}
