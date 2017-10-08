#include <stdio.h>

int clock[360];
int chk[360], chk2[360];
int main(){
	int h, m, s, dep, arr;
	scanf("%d %d %d %d %d", &h, &m, &s, &dep, &arr);

	clock[h*30==360?0:h*30]=1;
	clock[m*6==360?0:m*6]=1;
	clock[s*6==360?0:m*6]=1;

	for (int i=0; i<360; i++) {
		chk[i]=clock[i];
		chk2[i]=clock[i];
	}

	for (int i=dep*30; i<=(dep<arr?arr*30:arr*30+360); i++){
		chk[i%360+2]|=chk[i%360+1];
	}

	for (int i=(dep>arr?dep*30:dep*30+360); i>=arr*30; i--){
		chk2[(i-2)%360]|=chk2[(i-1)%360];
	}

	arr=arr*30==360?0:arr*30;
	if (chk[arr] && chk2[arr]) printf("NO\n");
	else printf("YES\n");
}
