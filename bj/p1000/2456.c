#include <stdio.h>

int a[4], b[4];
int ret(int x){
	if ( x==3 ) return 1000;
	else if ( x==2) return 1;
	else return 0;
}
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		int q, w, e; scanf("%d %d %d", &q, &w, &e);
		a[1]+=q, a[2]+=w, a[3]+=e;
		b[1]+=ret(q), b[2]+=ret(w), b[3]+=ret(e);
	}

	int mx=0, ans=0;
	for (int i=1; i<=3; i++) if ( mx < a[i]) mx=a[i], ans=i;
	
	int cnt=0;
	for (int i=1; i<=3; i++) if ( mx == a[i]) cnt++;

	if (cnt==1){
		printf("%d %d\n", ans, mx);
	} else {

		mx =0;int tmpmx=0;
		for (int i=1; i<=3; i++){
			if ( tmpmx < b[i] ) tmpmx=b[i],mx=a[i], ans=i;
		}
		cnt=0;
		for (int i=1; i<=3; i++) if ( tmpmx== b[i] ) cnt++;
		if (cnt==1) printf("%d %d\n", ans, mx);
		else printf("%d %d\n", 0, mx);
	}
}
