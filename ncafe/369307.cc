#include<stdio.h>
#include<algorithm>
int A[101][101], n, cnt, Size[101]; 
int da[4]={1, -1, 0, 0}, db[4] = {0, 0, 1, -1};

bool safe(int a, int b) {
	return (0 <= a && a < n) && (0 <= b && b < n);
}
bool cmp(int a, int b) { return a > b; }

/*
void dfs(int a, int b) {
	A[a][b] = 0;
	Size[cnt]++;
	if(safe(a+1, b) && A[a+1][b] == 1) dfs(a+1, b);
	if(safe(a-1, b) && A[a-1][b] == 1) dfs(a-1, b);
	if(safe(a, b+1) && A[a][b+1] == 1) dfs(a, b+1);
	if(safe(a, b-1) && A[a][b-1] == 1) dfs(a, b-1); 
}
*/
void dfs(int a, int b){
	A[a][b]=0;
	Size[cnt]++;
	for (int i=0; i<4; i++){
		int na = a+da[i], nb=b+db[i];
		if(safe(na, nb) && A[na][nb]==1) dfs(na, nb);
	}
}

void solve() {

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(A[i][j] == 1) {
				dfs(i, j);  
				cnt++;
			}

	std::sort(Size, Size+cnt, cmp);
}


int main() {

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &A[i][j]);

	solve( );

	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++) printf("%d\n", Size[i]);

	return 0;
}
