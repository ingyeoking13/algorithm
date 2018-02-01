#include <cstdio>

int a[101];
int main(){
	int n; scanf("%d",&n);
	int ans=0;
	while(n--){
		int tmp;
		scanf("%d", &tmp);
		if (a[tmp])  ans++;
		else a[tmp]=1;
	}
	printf("%d\n", ans);

}
