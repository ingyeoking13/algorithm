#include <stdio.h>

int a[4]={0, 1, 0, 0};
int main(){
	int n; scanf("%d", &n);
	while(n--){
		int x, y;
		scanf("%d %d", &x, &y);
		a[x]^=a[y], a[y]^=a[x], a[x]^=a[y];
	}
	for (int i=1; i<=3; i++) if(a[i]) printf("%d\n", i);
}
