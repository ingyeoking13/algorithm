#include <stdio.h>

int prime[4000001]={9, 1};
int arr[300000];
int main(){

	int n, ans=0;
	scanf("%d", &n);
	for (int i=2; i*i<=n; i++)
		if(!prime[i])
			for (int j=2*i; j<=n; j+=i)
			 	prime[j]=1;

	int i=0, j=2;
	do{
		if(!prime[j]) arr[i++]=j;
	}while(j++<n);

	int sum=arr[0];
	for(int l=0,r=0; r<i && l<=r;){
		if (sum==n){
			ans++;
			sum+=arr[++r];
		}
		else if (sum>n){
			sum-=arr[l++];
		}
		else if (sum<n){
			sum+=arr[++r];
		}
	}
	printf("%d\n", ans);
}
