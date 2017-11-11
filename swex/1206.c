#include <stdio.h>

int a[1003], b[1003];
int max(int x, int y) { if (x<y) return y; return x;}
int main(){
	
	for (int _tc =1; _tc<=10; _tc++){
		int n;
		scanf("%d", &n);

		for (int i=1; i<=n; i++) scanf("%d", &a[i]);
		b[1]=a[1]-max(max(a[0],a[2]),a[3]);

		for (int i=2; i<=n; i++) 
			b[i]=a[i]-max(max(max(a[i-1],a[i-2]),a[i+1]),a[i+2]);

		int ans=0;
		for (int i=0; i<=n; i++) if(b[i]>0)  ans+=b[i];

		printf("#%d %d\n", _tc, ans);
	}
}
