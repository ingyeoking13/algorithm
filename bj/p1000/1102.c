#include <stdio.h>

int w[16][16], d[1<<16]; char s[20];
int min(int x, int y){ return x<y?x:y; }
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) 
		for (int j=0; j<n; j++)
			scanf("%d", &w[i][j]);

	scanf("%s", s);
	int p; scanf("%d", &p);
	int state=0;
	for (int i=0; i<n; i++) if(s[i]=='Y') state|=(1<<i);

	for (int i=0; i<(1<<16); i++) d[i]=1<<25;
	d[state]=0;

	for (int i=state; i<(1<<n); i++){
		for (int j=0; j<16; j++){
			if (i&(1<<j)){
				for (int k=0; k<16; k++){
					if ((i&(1<<k))==0){
						d[i+(1<<k)]= min(d[i+(1<<k)], d[i]+w[j][k]);
					}
				}
			}
		}
	}

	int ans=1<<25;
	for (int i=0; i<(1<<n) ; i++){
		int cnt=0;
		for (int j=0; j<n; j++) {
			if (i&(1<<j)) cnt++;
		}
		if (cnt>=p) ans=min(ans, d[i]);
	}
	printf("%d\n", ans>=(1<<25)?-1:ans);
}
