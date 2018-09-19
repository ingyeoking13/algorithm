#include <stdio.h>

int a[105][105], cr[105], cc[105], n, l, b[105][105]; 
void chkr(int row){
	int now = a[row][0], chk=1;
	for (int i=0; i<n; i++)  if (a[row][i]!=now) chk=0;
	if (chk) cr[row]=1;
}
void chkc(int col){
	int now = a[0][col], chk=1;
	for (int i=0; i<n; i++)  if (a[i][col]!=now) chk=0;
	if (chk) cc[col]=1;
}
int bckchk(int sx, int sy, int dir){
	int chk=1; 
	if (dir==0){
		for (int i=0; i<l; i++){
			if (sy-i<0) {chk=0; break;}
			if (b[sx][sy-i]&1) chk=0;
		}
	}
	else {
		for (int i=0; i<l; i++){
			if (sx-i<0) {chk=0; break; }
			if (b[sx-i][sy]&2) chk=0;
		}
	}
	return chk;
}
int main(){
	scanf("%d %d", &n, &l);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for (int i=0; i<n; i++) chkr(i); 
	for (int i=0; i<n; i++) chkc(i);

	for (int i=0; i<n; i++){
		if (!cr[i]){
			int now=a[i][0];
			for (int j=1; j<n; j++){
			int chk=3;

			if (now!=a[i][j]){
				if (now==a[i][j]+1 && !(b[i][j]&1)){
					int k=0;
					while (k<l && a[i][j+k]+1==now && j+k<n) k++; 
					if (k!=l) chk=0;
					else{
						for (k=0; k<l; k++) b[i][j+k]|=1;
					}
				}
				else if (now==a[i][j]-1 && bckchk(i, j-1, 0)){
					int k=0; now=a[i][j]; chk=2;
					while (k<l && a[i][j-k-1]==now-1 && j-k-1>=0) k++; 
					if (k!=l) chk=0;
					else{
						for (k=0; k<l; k++) b[i][j-k-1]|=1;
					}
				}
				else chk=0;
			}
			else if (now==a[i][j]) chk&=1;

			if (!chk) break;
			else if (chk==3) j+=l-1, now=a[i][j];
			if (j==n-1) cr[i]=1;
			}
		}
	}

	for (int j=0; j<n; j++){
		if (!cc[j]){
			int now=a[0][j];
			for (int i=1; i<n; i++){
				int chk=3;

				if (now!=a[i][j]){
					if (now==a[i][j]+1 && !(b[i][j]&2)){
						int k=0;
						while (k<l && now==a[i+k][j]+1 && i+k<n) k++;
						if (k!=l) chk=0;
						else {
							for (k=0; k<l; k++) b[i+k][j]|=2;
						}
					}
					else if (now==a[i][j]-1 && bckchk(i-1, j, 1)){
						int k=0; now=a[i][j]; chk=2;
						while (k<l && now-1==a[i-k-1][j] && i-k-1>=0) k++;
						if (k!=l) chk=0;
						else {
							for (k=0; k<l; k++) b[i-k-1][j]|=2;
						}
					}
					else chk=0;
				}
				else if (now==a[i][j]) chk&=1;

				if (!chk) break;
				else if (chk==3) i+=l-1, now=a[i][j];
				if (i==n-1) cc[j]=1;
			}
		}
	}

	int ans=0;
	for (int i=0; i<n; i++) ans=ans+cc[i]+cr[i];
	printf("%d\n", ans);
}
