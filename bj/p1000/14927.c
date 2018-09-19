#include <stdio.h>
typedef enum{false, true}bool;
int a[18][18], h, t; 
bool c[1LL<<36];
long long q[100000];
int main(){

	int n; scanf("%d", &n);
	long long now=0;
	for (int i=0; i<n*n; i++){
		scanf("%d", &a[i/n][i%n]);
		now+=(((long long)a[i/n][i%n])<<i);
	}
	c[now]=1; 
	q[t++]=now;
	while(h<t){
		now = q[h++];
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){

				int na[18][18];
				for (int k=n-1; k<n; k++){
					for (int l=n-1; l<n; l++){
						na[k][l]=now%2;
						now>>=1;
					}
				}

				na[i][j]^=1;
				if (i-1>=0) na[i-1][j]^=1;
				if (i+1<n) na[i+1][j]^=1;
				if (j-1>=0) na[i][j-1]^=1;
				if (j+1<n) na[i][j+1]^=1;

				long long next=0;
				for (int k=0; k<n*n; k++){
					next+=(((long long)na[k/n][k%n])<<k);
				}
				if (!c[next]) {
					c[next]=c[now]+1;
				}
			}
		}
	}
}
