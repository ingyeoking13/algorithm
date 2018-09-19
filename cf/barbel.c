#include <stdio.h>
#include <stdlib.h>

int n, m;
int input[15], b[15];
int arr1[1<<10], arr2[1<<10], arri=0;

int mycmp(const void* a, const void* b){
	return *(int *)a - *(int *)b;
}
void dfs1(int sum, int i){
	if (i<m/2){
		int nsum = sum+b[i];
		dfs1(nsum, i+1);
		dfs1(sum, i+1);
	}
	else arr1[arri++]=sum;
}

void dfs2(int sum, int i){
	if (i<m){
		int nsum =sum+b[i];
		dfs2(nsum, i+1);
		dfs2(sum, i+1);
	}
	else arr2[arri++]=sum;
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++) scanf("%d", &input[i]);
	for (int i=0; i<m; i++) scanf("%d", &b[i]);

	dfs1(0, 0); arri=0;
	dfs2(m/2, 0);

	int a=1<<m/2;
	int b=1<<m-m/2;
	arr1[a-1]=0; arr2[b-1]=0;

	qsort(arr1, a, sizeof(int), mycmp);
	qsort(arr2, b, sizeof(int), mycmp);

	for (int i=0; i<n; i++){
		int l=0, r=0, ans[1<<15]; arri=0;
		while(r<b && l<a){
			if  (arr1[l]>arr2[r]) r++;
			else if (arr1[l]<arr2[r]) l++;
			else {
				printf("%d\n", arr1[l]+input[i]);
				int lenl=1, lenr=1;
				int peg=r+1;
				while(peg <b && arr1[peg++]==arr2[r]) lenr++;
				peg=l+1;
				while(peg <a && arr1[peg++]==arr1[l]) lenl++;
				l+=lenl; r+=lenr;
			}
		}
	}

}
