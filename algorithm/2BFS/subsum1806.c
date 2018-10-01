#include <stdio.h>

int main(){

	int n, obj, ans=100001;
	int arr[100001];
	scanf("%d %d", &n, &obj);

	for (int i=0; i<n; i++) scanf("%d", &arr[i]);

	int sum=arr[0];
	int len;
	for(int l=0, r=0; r<n;){
		if (sum<obj) {r++; sum+=arr[r];}
		else if (sum>obj) {
			len=r-l+1;
			if (ans> len) ans=len;
			if (l==r){ r++; sum+=arr[r]; } 
			else {sum-=arr[l];l++;}
		}
		else if (sum==obj) {
			len=r-l+1;
			if (ans> len) ans=len;
			r++;
			sum+=arr[r];
		}
	}
	if(ans>n) printf("0\n");
	else printf("%d\n", ans);
}
