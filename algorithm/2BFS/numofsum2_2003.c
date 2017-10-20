#include <stdio.h>

int main(){

int n, obj, ans=0;
int arr[10001];
scanf("%d %d", &n, &obj);

for(int i=0; i<n; i++) scanf("%d", &arr[i]);


int sum=arr[0];
int r=0, l=0;
while(r<n){
	if(sum<obj) { r++; sum += arr[r];}
	else if (sum > obj) {
	 	if (l==r){r++; sum+=arr[r];} 
		else { sum-= arr[l]; l++;}
	}
	else if (sum==obj) {ans++;r++; sum+=arr[r];}
}

printf("%d\n", ans);
}

