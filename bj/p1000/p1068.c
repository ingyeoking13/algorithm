#include <stdio.h>

int tmp, c[51][51], root, n, ans=0;
void reaf(int now){
	int chk=0;
	for (int i=0; i<n; i++){
		if (c[now][i]>0) { reaf(i); chk=1;}
	}
	if (!chk) ans++;
}

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &tmp);
		if(tmp==-1) root=i;
		else c[tmp][i]=1;
	}

	scanf("%d", &tmp);
	if (tmp==root) {printf("0\n"); return 0;}
	for (int i=0; i<n; i++){ c[i][tmp]=-2; }

	reaf(root);
	printf("%d\n", ans);
}
