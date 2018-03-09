#include <bits/stdc++.h>

int a[100000], b[100001], c[100001], d[100000];
int main(){

	int n; scanf("%d", &n);
 	long long sum=0;
	int min = 100001, max = -100001;

	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	 	sum += (long long)a[i];
		if ( a[i] > max ) max = a[i];
		if ( a[i] < min ) min = a[i];

		if ( a[i] >=0 ) b[a[i]]++;
	 	else c[-a[i]]++;
	}

	int N=n, ans=0;
	if ( max-min<=1){

		for (int i=0; i<n; i++){
			d[i]=sum/N;

			if ( d[i] >= 0 && b[d[i]] ) ans++, b[d[i]]--;
			else if ( d[i] < 0 && c[-d[i]]) ans++,c[-d[i]]--;	

			sum-=d[i], N--;
		}
	}
	else{
		int mid = (max+min)/2;
		int m=0, u=0, l=0;
		if ( mid <0)  m=c[-mid]; else m=b[mid];
		if ( max <0)  u=c[-max]; else u=b[max];
		if ( min <0)  l=c[-min]; else l=b[min];
		
		for (int i=0; i<l; i++) d[i]=min; 
		for (int i=l; i<l+m; i++) d[i]=mid; 
		for (int i=l+m; i<n; i++) d[i]=max; 

		ans= n;
		if (m/2*2 <= (u>l?l:u)*2 ){
			for (int i=0; i<n/2; i++) {
				if ( d[i] == min  && d[n-i-1] == max){
					d[i]=d[n-i-1]=mid;
					ans-=2;
				}
			}
		}
		else {
			for (int i=l; i<l+m; i+=2){
				if ( d[i] == mid && d[i+1] == mid){
					d[i]=min, d[i+1]=max;
					ans-=2;
				}
			}	
		}
	}
	printf("%d\n", ans);
	for (int i=0; i<n; i++) printf("%d ", d[i]);
	printf("\n");
}
