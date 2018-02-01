#include <cstdio>

int a[9], b[9];
int main(){

	for (int i=0; i<9; i++) scanf("%d", &a[i]);
	for (int i=0; i<9; i++) scanf("%d", &b[i]);

	int suma=0, sumb=0, chk=0;
	for (int i=0; i<9; i++){
		suma+=a[i];
		if ( suma> sumb ) chk=1;
		sumb+=b[i];
	}
  printf((suma<sumb && chk)?"YES\n":"NO\n");
}
