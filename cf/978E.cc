#include <stdio.h>

using namespace std;

struct state{ int l, r, lbuf, rbuf;};
state d[1001];

int main(){
	int n, w; scanf("%d %d", &n, &w);

	d[0]={0, w, 0, w};
	int sum=0;

	for(int i=1; i<=n; i++){
		d[i] = {d[i-1].l, d[i-1].r, d[i-1].lbuf, d[i-1].rbuf};

		int tmp; 
		scanf("%d", &tmp);
		if( d[i].rbuf+tmp> w) {

			d[i].r -= d[i].rbuf+ tmp-w;
			d[i].rbuf = w-tmp;

		}else if ( d[i].lbuf+tmp < 0) {

			d[i].l += d[i].lbuf-tmp;
			d[i].lbuf = -tmp;

		}
		d[i].rbuf += tmp; 
		d[i].lbuf += tmp;
		printf("%d %d %d %d %d \n", i, d[i].r, d[i].l, d[i].rbuf, d[i].lbuf);

	}
	if ( d[n].r-d[n].l+1 < 0) printf("0\n");
	else printf("%d\n",d[n].r- d[n].l+1);

}
