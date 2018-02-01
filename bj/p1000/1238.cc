#include <cstdio>
#define INF 100001

int dist[1001][1001];
int main(){
	int n, m, x; scanf("%d %d %d", &n, &m, &x);

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) 
			if ( i!=j ) dist[i][j]=INF;

	while(m--){
		int u, v, w;  scanf("%d %d %d", &u, &v, &w);
		dist[u][v]=w;
	}

	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				if ( dist[i][j] > dist[i][k] + dist[k][j] )
					dist[i][j] = dist[i][k] + dist[k][j];

	int max=0;
	for (int i=1; i<=n; i++) 
		if (max < dist[i][x] + dist [x][i]) 
			max= dist[i][x]+dist[x][i];

	printf("%d\n", max);
}
