//Educational Codeforces Round 29 .. WA at 10 tc
// need more awesome trick
#include <stdio.h>

int a[4][4], b[4][4];
int game(int a, int b){
	if (a==b) return 1;
	if (a>b){
		if (a==3 && b==1) return 2;
		return 0;
	}
	else if (b>a){
		if (b==3 && a==1) return 0; 
		return 2;
	}
}

int main(){

	long long k;
  int	as, bs;
	scanf("%lld %d %d", &k, &as, &bs);

	for (int i=1; i<=3; i++){
		for (int j=1; j<=3; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for (int i=1; i<=3; i++){
		for (int j=1; j<=3; j++){
			scanf("%d", &b[i][j]);
		}
	}

	long long ascore=0, bscore=0, now;
	now=game(as, bs);
	if (now==2) bscore++; 
	else if (now==0) ascore++;

	for (long long i=1; i<k; i++){
		int p=game(a[as][bs], b[as][bs]);
		int ap=as, bp = bs;
		as=a[ap][bp]; bs=b[ap][bp];
		if (p==2)  bscore++; 
		else if (p==0) ascore++;
	}
	printf("%lld %lld\n", ascore, bscore);
}
