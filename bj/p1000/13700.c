#include <stdio.h>

int p[100001], d[100001], q[400000];
int  h, t;
int main(){
	int n, s, dst, f, b, k;
	scanf("%d %d %d %d %d %d", &n, &s, &dst, &f, &b, &k);

	for (int i=0; i<k; i++) {
		int tmp;
		scanf("%d",&tmp);
		p[tmp]=1;
	}

	q[t++]=s; d[s]=0;
	while (h<t){
		int now=q[h++];

		if (now+f<=n && !p[now+f] && !d[now+f]){
			q[t++]= now+f;
			d[now+f] = d[now]+1;
		}
		if (now-b>0 && !p[now-b] && !d[now-b] && now-b != s){
			q[t++]= now-b;
			d[now-b] = d[now]+1;
		}
	}
	if (d[dst]) printf("%d\n", d[dst]);
	else printf("BUG FOUND\n");
}
