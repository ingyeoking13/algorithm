#include <stdio.h>

int a[20][20], p[20];
void swap(int x, int y) { p[x]^=p[y], p[y]^=p[x], p[x]^=p[y]; }

int perm(int n){
	int i=n-1;
	while(i>0 && p[i-1]>p[i]) i--;
	if (i==0) return 0;
	int j=n-1;
	while(p[i-1]>p[j]) j--;
	swap(i-1, j);
	j=n-1;
	while(i<j){
		swap(i, j);
		j--;
		i++;
	}
	return 1;
}
int main(){
	int n; scanf("%d", &n);
	//init
	for (int i=0; i<n; i++){
		for (int j=0; j<=i; j++){
			scanf("%d", &a[i][j]);
			a[j][i]=a[i][j];
		}
	}
	for (int i=0; i<n; i++) p[i]=i;

	//find answer
	int ans=1<<20;
	do{
		if(p[0]==0){
			int sum=0;
			for (int i=1; i<n; i++){
				sum+=a[p[i-1]][p[i]];
			}
			sum+=a[p[n-1]][p[0]];
			if (sum<ans) ans=sum;
		}
	}while(perm(n));
	printf("%d\n", ans);
}
