#include <stdio.h>
#include <algorithm>
using namespace std;

char s[100][101], tmp[101];
int a[4], b[4], c[2]={0, 1};
int mn=1e9;

void dfs(int now, int ca, int cb, int cnt){
	if ( now == 4) {
		if ( ca > 2 || cb >2 ) return;
		if ( cnt < mn ) mn = cnt;
		return ;
	}

	dfs(now+1, ca+1, cb, cnt+a[now]);
	dfs(now+1, ca, cb+1, cnt+b[now]);

}

int main(){
	int n; scanf("%d", &n);

	for (int i=0; i<4; i++){
		for (int j=0; j<n; j++) scanf("%s", s[j]);

//		for (int j=0; j<n; j++) printf("%s\n", s[j]);
		for (int j=0; j<2; j++){
			for (int k=0; k<n; k++){
				for (int l=0; l<n; l++){
					if( j==0 ) {
						a[i] += (s[k][l]==(c[(l+k)%2]+'0'));
					}
					else if (j==1) b[i] += (s[k][l] == (c[(l+k+1)%2]+'0'));
				}
			}
		}
	}
//	for (int i=0; i<4; i++) printf("a: %d\n", a[i]);
//	for (int i=0; i<4; i++) printf("b: %d\n", b[i]);
	dfs(0, 0, 0,0);
	printf("%d\n", mn);
}
