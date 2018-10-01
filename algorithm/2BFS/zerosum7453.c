#include <stdio.h>
#include <stdlib.h>

int a[4000], b[4000], c[4000], d[4000];
int m1[16000000], m2[16000000];

int mycmp(const void* a, const void* b){
	return *(int *)a-*(int *)b;
}

int main(){

	int n;
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
		scanf("%d", &b[i]);
		scanf("%d", &c[i]);
		scanf("%d", &d[i]);
	}

	int k=0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			m1[k++]=a[i]+b[j];
		}
	}

	k=0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			m2[k++]=c[i]+d[j];
		}
	}

  n=n*n;
	qsort(m1, n, sizeof(int), mycmp);
	qsort(m2, n, sizeof(int), mycmp);

	int l=0, r=n-1;
  long long	ans=0;
	while(l<n && r>=0){
		if (m1[l]+m2[r]<0) l++;
		else if (m1[l]+m2[r]>0) r--;
		else{
			long long lenl=1, lenr=1;
			int peg=l+1;
			while(peg<n && m1[l]==m1[peg++]) lenl++;
			peg=r-1;
			while(peg>=0 && m2[r]==m2[peg--]) lenr++;
			ans+=lenl*lenr;
			r-=lenr;
			l+=lenl;
		}
	}

	printf("%lld\n", ans);
	return 0;
}
