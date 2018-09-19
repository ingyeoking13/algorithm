#include <stdio.h>

int a[10001];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	int obj; scanf("%d", &obj);

	int tmp=obj, max=0;
	for (int i=0; i<n; i++){
		tmp-=a[i];
		max=a[i]>max?a[i]:max;
	}
	if (tmp>=0) return printf("%d\n", max);

	int l = obj/n, r=max;
	while (l<= r){
		int m = (l+r)/2;
		tmp=obj;

		for (int i=0; i<n; i++){
			if (m>=a[i]) tmp -= a[i];
			else tmp -= m;
		}
		if (tmp >=0) l = m+1;
		else r = m-1;
	}
	printf("%d\n", r);
}
