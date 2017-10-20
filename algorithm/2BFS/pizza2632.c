#include <stdio.h>
#include <stdlib.h>
int obj, a[1000], b[1000];
int c[999010], d[999010];
int mycmp(const void* a, const void* b){
	return *(int *)a - *(int *)b;
}
int main(){

	int m, n;
	scanf("%d", &obj);
	scanf("%d %d", &m, &n);

	for(int i=0; i<m;i++) scanf("%d", &a[i]);
	for(int i=0; i<n;i++) scanf("%d", &b[i]);

	int k=0;
	for(int i=0; i<m;i++){
		c[k++]=a[i];
		for(int j=i+1; j<i+m-1;j++){
			c[k]=a[j%m]+c[k-1];
			k++;
		}
	}
	int sum=0;
	for (int i=0; i<m;i++) sum+=a[i];
	c[k++]=0; c[k++]= sum;
	int csize=k;

	k=0;
	for(int i=0; i<n;i++){
		d[k++]=b[i];
		for(int j=i+1; j<i+n-1;j++){
			d[k]=b[j%n]+d[k-1];
			k++;
		}
	}
	sum=0;
	for (int i=0; i<n;i++) sum+=b[i];
	d[k++]=0; d[k++]= sum;
	int dsize=k;

	qsort(c,csize ,sizeof(int),mycmp);
	qsort(d,dsize ,sizeof(int),mycmp);

	int l=0, r=dsize-1;
	long long ans=0;
	while(l<csize && r>=0){
		if(c[l]+d[r]<obj) l++;
		else if (c[l]+d[r]>obj) r--;
		else {
			long long lenl=1, lenr=1;
			int peg=l+1;
			while(peg<csize && c[peg++]==c[l]) lenl++;
			peg=r-1;
			while(peg>=0 && d[peg--]==d[r]) lenr++;
			ans+=lenl*lenr;
			l+=lenl;
			r-=lenr;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
