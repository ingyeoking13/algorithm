#include <stdio.h>
int max(int a, int b){ if (a>b) return a; return b; }
int main(){
	int s[1000], n;
	int d[1000][2];
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &s[i]);

	d[0][0]=1; d[0][1]=1;

	for (int i=1; i<n; i++){
		d[i][0]=1; d[i][1]=1;
		for (int j=0; j<i; j++){
			if (s[i]>s[j]){
				if (d[i][0]<d[j][0]+1)
					d[i][0]=d[j][0]+1;
			}
			else if (s[i]<s[j]){
				int tmp=max(d[j][0]+1,d[j][1]+1);
				d[i][1]=d[i][1]<tmp?tmp:d[i][1];
			};
		}
	}
	int ans=0;
	for (int i=0; i<n; i++){
		ans=ans<max(d[i][0],d[i][1])?max(d[i][0],d[i][1]):ans;
	}
	printf("%d\n", ans);
}
