#include <stdio.h>
#include <string.h>


int n, m, f, t;
int head, tail;
int d[500], inQ[500], q[100], pcnt[100], p[100][100];
int e[500][500];

void dfs(int now){
	if ( now == -1 ) return;
	for (int i=0; i<pcnt[now]; i++){
		e[p[now][i]][now] =-1;
		dfs(p[now][i]);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	scanf("%d %d", &f, &t);

	while(m--){
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		e[u][v]=w;
	}

	memset(d, 0x3f, sizeof(d));
	memset(p, -1, sizeof(p));
	d[f] =0;
	q[tail++] = f;

	while(head<tail){ // spfa
		int now = q[head++];
		inQ[now]=0;

		for (int i=0; i<n; i++){

			if ( e[now][i] ){

				if ( d[i] >= d[now]+ e[now][i]  ){
					if( d[i] > d[now]+ e[now][i] ) pcnt[i]=0;

					d[i] = d[now] + e[now][i];
					p[i][pcnt[i]++] = now;
					if ( !inQ[i]) inQ[i]=1, q[tail++] = i;
				}
			}
		}
	}

	dfs(t); // destroy edge

	memset(d, 0x3f, sizeof(d));
	d[f] =0;
	head = tail=0;
	q[tail++] = f;

	while(head<tail){ // spfa
		int now = q[head++];
		inQ[now]=0;

		for (int i=0; i<n; i++){

			if ( e[now][i]> 0 ){

				if ( d[i] > d[now]+ e[now][i]  ){

					d[i] = d[now] + e[now][i];
					p[i][pcnt[i]++] = now;
					if ( !inQ[i]) inQ[i]=1, q[tail++] = i;
				}
			}
		}
	}

	if ( d[t] == 0x3f3f3f3f) printf("-1\n");
	else printf("%d\n", d[t]);
}
