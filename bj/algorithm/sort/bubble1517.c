#include <stdio.h>

int arr[500000];
int tmp[500000];
long long merge(int, int, int);
long long mergesort(int l, int r){
	long long inv=0;

	if (r>l){
		int m= (l+r)/2;
		inv += mergesort(l, m);
		inv += mergesort(m+1, r);
		inv += merge(l, m+1, r);
	}
	return inv;
}
long long merge(int l, int m, int r){
	int i = l, j = m, k=l;
	long long inv=0;

	while((i<=m-1) && (j<=r)){
		if( arr[i]<= arr[j]){
			tmp[k++]=arr[i++];
		}
		else{
			tmp[k++]=arr[j++];
			inv+=m-i;
		}
	}
	while(i<=m-1) tmp[k++] = arr[i++];
	while(j<=r) tmp[k++] = arr[j++];
	for (i=l; i<=r; i++) arr[i]=tmp[i];
	return inv;
}
int main(){

	int n, ans=0;
	scanf("%d", &n);
	for(int i=0; i<n;i++) scanf("%d", &arr[i]);

	printf("%lld\n", mergesort(0, n-1));
}
