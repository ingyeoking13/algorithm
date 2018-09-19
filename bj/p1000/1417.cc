#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1000];
int main(){
	int n; scanf("%d", &n);
	int my; scanf("%d", &my);

	for (int i=0; i<n-1; i++) scanf("%d", &a[i]);
	sort(a, a+n-1);
	int ans=0;
	while(my<=a[n-2]){
		a[n-2]--;
		my++;
		sort(a, a+n-1);
		ans++;
	}
	printf("%d\n", ans);

}
