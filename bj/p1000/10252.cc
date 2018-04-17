#include <stdio.h>

using namespace std;
void print(int a, int b) { if( a || b) printf("(%d,%d)\n", a, b); }
int main(){
	int T; scanf("%d", &T);

	while(T--){
		int n, m; scanf("%d %d", &n, &m);
		printf("1\n");

		if (n&1==1){
			printf("(0, 0)\n");
			print(0, m-1);
			for (int i=1; i<n; i++) print(i, m-1);
			for (int i=n-1; i>=0; i--){
				if ( i%2 ==0){
				 	for (int j=m-2; j>=0; j--) print(i, j);
				}
				else for (int j=0; j<=m-2; j++) print(i, j);
			}
		}
		else if( n&2==0 && m%2==0){
			printf("(0, 0)\n");
			print(n-1, 0);
			for (int i=1; i<m; i++) print(n-1, i);

			for (int i=m-1; i>=0; i--){
				if ( i%2 ==1){
					for (int j=0; j<n-1; j++) print(j, i);
				}
				else for (int j=n-1; j>=0; j--) print(j, i);
			}
		}
		else {
			printf("(0, 0)\n");
			print(n-1, 0);
			for (int i=1; i<m; i++) print(n-1, i);

			for (int i=m-1; i>=0; i--){
				if ( i%2== 0){
					for (int j=n-2; j>=0; j--) print(j, i);
				}
				else for (int j=0; j<=n-2; j++) print(j, i);
			}
		}
	}
}
