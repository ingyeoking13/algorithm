#include <bits/stdc++.h>

int a[100000], b[100001], c[100001], d[100000];
int main(){

	int n; scanf("%d", &n);
 	long long sum=0;
	int min = 100001, max = -100001;

	for (int i=0; i<n; i++){
		scanf("%lld", &a[i]);
	 	sum += (long long)a[i];

		if ( a[i] > max ) max = a[i];
		if ( a[i] < min ) min = a[i];

		if ( a[i] >=0 ) b[a[i]]++;
	 	else c[-a[i]]++;
	}

	int N=n, ans=0;
	if ( max- min<=1){

		for (int i=0; i<n; i++){
			d[i]=sum/N;
			if ( d[i] >= 0 && b[d[i]] ) ans++, b[d[i]]--;
			else if ( d[i] < 0 && c[-d[i]]) ans++,c[-d[i]]--;

			sum-=d[i], N--;
		}
	}
	else{
		int mid = (max+min)/2;

		int q, w, e, tmp;
		if ( mid <0)  q=c[-mid]; else q=b[mid];
		if ( mid+1 <0)  w=c[-(mid+1)]; else w=b[mid+1];
		if ( mid-1 <0)  e=c[-(mid-1)]; else e=b[mid-1];

		tmp=q;
		if (tmp 



	}

	printf("%lld\n", ans);
	for (int i=0; i<n; i++) printf("%lld ", d[i]);
	printf("\n");
}
