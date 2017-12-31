#include <stdio.h>

char s[51][51], s2[101];
int a[4]={0, 1, 2, 3}; 
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void swp(int i, int j){ a[i]^=a[j], a[j]^=a[i], a[i]^=a[j]; }

int perm(){
	int i=3;
	while ( i>0 && a[i-1]>a[i]) i--;
	if (!i) return 0;
	int j=3;
	while ( a[j] < a[i-1] ) j--;
	swp(i-1, j);

	j=3;
	while(i<j){
		swp(i, j);
		i++, j--;
	}
	return 1;
}

int main(){
	int row, col; scanf("%d %d", &row, &col);
	for (int i=0; i<row; i++) scanf("%s", s[i]);
	scanf("%s", s2);

	int start, end;
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if (s[i][j]=='S') start=i*col+j;
			if (s[i][j]=='E') end=i*col+j;
		}
	}

	int ans=0;
	do {
		int now=start;
		int x= now/col, y=now%col;

		for (int i=0; s2[i]; i++){
			x+=dx[a[s2[i]-'0']], y+=dy[a[s2[i]-'0']];
			if (!(0<= x && x<row && 0<=y && y<col))  break;
			if ( s[x][y] == 'E' ) {
				ans++;
				break;
			}
			else if ( s[x][y] == '#') break;
		}

	}while(perm());
	printf("%d\n", ans);
}
