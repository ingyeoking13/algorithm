#include <stdio.h>

int a[100001];
void swap(int *x, int *y){ *x^=*y, *y^=*x, *x^=*y; };
void heapify(int now, int len){
	int largest=now;
	int l = now*2, r= now*2+1;
	if ( l <= len && a[now] < a[l] ) largest=l;
	if ( r <= len && a[largest] < a[r] ) largest=r;

	if (largest!=now){
		swap(a[largest], a[now]);
		heapify(largest, len);
	}
}
int deheap(int len){
	int ret= a[1];
	swap(a[1], a[
	heapify(



}

int main(){

	int n, len=1; scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		int tmp; scanf("%d", &tmp);
		if (!tmp) {
			printf("%d\n",deheap(len-1));
			if (len>1) len--;
		}
		else {
			a[len]=tmp;
			swap(a[1], a[len]);
			heapify(1, len);
			len++;
		}
	}

}
