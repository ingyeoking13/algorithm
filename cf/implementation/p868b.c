#include <stdio.h>

int clock[3600];
int chk[3600], chk2[3600];
int main(){
	int h, m, s, dep, arr;
	scanf("%d %d %d %d %d", &h, &m, &s, &dep, &arr);

	clock[(h*300+m*60+6*s)%3600]=1;
	clock[(m*60+s*6)%3600]=1;
	clock[(s*60)%3600]=1;

//	printf("%d %d %d\n", (h*30+m*6)%360, (m*6+s*6)%360, s*6%360);

	for (int i=0; i<3600; i++) {
		chk[i]=clock[i];
		chk2[i]=clock[i];
	}

	for (int i=dep*300; i<=(dep<arr?arr*300:arr*300+3600); i++){
		chk[(i+1)%3600]|=chk[i%3600];
	}

	for (int i=(dep>arr?dep*300:dep*300+3600); i>=arr*300; i--){
		chk2[(i-1)%3600]|=chk2[i%3600];
	}

	arr=(arr*300)%3600;
	if (chk[arr] && chk2[arr]) printf("NO\n");
	else printf("YES\n");
}
