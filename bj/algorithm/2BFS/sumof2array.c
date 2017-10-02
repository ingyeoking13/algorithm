#include <stdio.h>
#include <stdlib.h>

int a[1000], b[1000];
int c[500502], d[500502];
int mycmp(const void* a, const void* b){
	return *(int *)a - *(int *)b;
}

int main(){

	int obj, m, n;
	scanf("%d", &obj);

	scanf("%d", &m); 
	for (int i=0; i<m; i++) scanf("%d", &a[i]);

	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &b[i]);

	int k=0;
	for (int i=0; i<m; i++){
		c[k++]=a[i];
		for (int j=i+1; j<m; j++){
			c[k]=a[j]+c[k-1];
			k++;
		}
	}
	int csize=k;

	k=0;
	for (int i=0; i<n; i++){
		d[k++]=b[i];
		for (int j=i+1; j<n; j++){
			d[k]=b[j]+d[k-1];
			k++;
		}
	}
	int dsize=k;

	qsort(c, csize, sizeof(int), mycmp);
	qsort(d, dsize, sizeof(int), mycmp);

	int l=0, r=dsize-1;
	long long ans=0;
	while(l<csize && r>=0){
		if(c[l]+d[r]<obj) l++;
		else if (c[l]+d[r]>obj) r--;
		else{
			long long lenl=1, lenr=1;
			int peg=l+1;
			while(peg<csize && c[peg++]==c[l]) lenl++;
			peg=r-1;
			while(peg>=0 && d[peg--]==d[r]) lenr++;
			ans += lenl*lenr;
			r-=lenr;
			l+=lenl;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
