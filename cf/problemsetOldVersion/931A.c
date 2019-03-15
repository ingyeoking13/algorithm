#include <stdio.h>

int swp(int *x, int* y){
	int tmp =  *x; *x = *y; *y= tmp;
}

int main(){

	int n, m; scanf("%d %d", &n, &m);
	if (n > m ) swp(&n, &m);

	int ans=0;
	int mid = (n+m)/2;

	int cnt=1;
	for (int i=n; i<mid; i++) {
		ans+=cnt;
		cnt++;
	}
	cnt=1;
	for (int i=m; i>mid; i--) {
		ans+=cnt;
		cnt++;
	}

	printf("%d\n", ans);

}
