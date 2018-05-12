#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char a[102], b[102], c[102];
int d[102][102][102];

int main(){
	scanf("%s %s %s", a+1, b+1, c+1);
	int alen = strlen(a+1), blen = strlen(b+1), clen = strlen(c+1);

	for (int i=1; i<=alen; i++){
		for (int j=1; j<=blen; j++){
			for (int k=1; k<=clen; k++){
				if (a[i] == b[j] && c[k] == a[i] ) d[i][j][k] = d[i-1][j-1][k-1]+1;
				else d[i][j][k] = 
				max({d[i-1][j-1][k], d[i-1][j][k-1], d[i][j-1][k-1], 
						d[i][j][k-1], d[i][j-1][k], d[i-1][j][k]});
			}
		}
	}
	printf("%d\n", d[alen][blen][clen]);
}
