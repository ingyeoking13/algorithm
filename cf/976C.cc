#include <stdio.h>

bool chk[300000*4];

int exist(int f, int t, int now){
	if (f == t) return chk[now]=1;

	int m = (f+t)/2;
	int le = exist(f, m, now*2);
	int re = exist(m+1, t, now*2+1);
	return chk[now] =(le || re);
}

int main(){
	int n; scanf("%d", &n);
	int f, t;
	for (int i=0; i<n; i++) {
		scanf("%d %d", &f, &t);
		exist(f, t, 1);
	}



}

