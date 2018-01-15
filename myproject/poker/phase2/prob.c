#include <stdio.h>
#include <string.h>
#include "prob.h"
#include "iohelper.h"

int (*func[8])(long long, long long ) = {
	onePair, twoPair, triple, straight,
	flush, fullhouse , fourCard, straightFlush
};
char* str[8]={
	"OnePair", "TwoPair", "Triple", "Straight",
	"Flush", "Full House", "Four Card", "Straight Flush"
};
int len[8] ={7, 7, 6, 8, 5, 10, 9, 14};

void calcProb(int n, long long player[8], int man, long long table , int turn){
	long long other=0;
	for (int i=0; i<man; i++){
		other|=player[i];
	}
	other|=table;
	other&=~player[n];

	long long mystate = player[n] | table;

	if (turn ==1){ 	//0 community card

		for (int f=0; f<8; f++){
			printf("%s probability :> ", str[f]); 
			double cnt=0;

			for (int i=0; i<52; i++){
				if ( !(mystate & (1LL<<i))){ //1

					long long tmp = mystate|(1LL<<i);
					for (int j=i+1; j<52; j++){
						if ( !(tmp & (1LL<<j))){ //2

							tmp |= 1LL<<j;
							for (int k=j+1; k<52; k++){
								if ( !(tmp & (1LL<<k))) { //3

									tmp |= 1LL<<k;
									for (int l=k+1; l<52; l++){
										if ( !(tmp & (1LL<<l)) ) { //4

											tmp |= 1LL<<l;
											for (int m =l+1; m<52; m++){
												if ( !(tmp & (1LL<<m)) ) { //5

													tmp |= 1LL<<m;

													if( func[f](tmp, other ) ){
														cnt++;
													}

													tmp &= ~(1LL<<m);
												}
											}

											tmp &= ~(1LL<<l);
										}
									}

									tmp &= ~(1LL<<k);
								}
							}

							tmp &= ~(1LL<<j);
						}
					}

				}
			}

			for (int i=0; i<20; i++) printf(" ");
			for (int i=0; i<len[f]-len[4]; i++) printf("\b");
			printf("%.03lf\n", cnt*120/(50*49*48*47*46)*100);
		}
	}
	else if (turn ==2){ //3 community card

		for(int f=0; f<8; f++){
			printf("%s probability :> ", str[f]);
			double cnt=0;

			for (int i=0; i<52; i++){
				if ( !(mystate & 1LL<<i) ){ //1

					long long tmp = mystate|(1LL<<i);
					for (int j=0; j<52; j++){
						if ( !(tmp & 1LL<<j) ){ //2
							tmp |=1LL<<j;
							
							if( func[f](tmp, other) ){
								cnt++;
							}

							tmp &= ~(1LL<<j);
						}
					}
				}
			}

			for (int i=0; i<20; i++) printf(" ");
			for (int i=0; i<len[f]-len[4]; i++) printf("\b");
			printf("%.03lf\n", cnt/(47*46)*100);
		}
	}	
	else if (turn ==3 || turn ==4){ //4 community card

		for (int f=0; f<8; f++){
			printf("%s probability :> ", str[f]);
			double cnt=0;

			for (int i=0; i<52; i++){
				if ( !(mystate & 1LL<<i) ){
					long long tmp = mystate|(1LL<<i);

					if ( func[f](tmp, other) ){
						cnt++;
					}

				}
			}

			for (int i=0; i<20; i++) printf(" ");
			for (int i=0; i<len[f]-len[4]; i++) printf("\b");
			printf ("%.03lf\n", turn==3?cnt/46*100:cnt/45*100);
		}
	}

}

int onePair(long long mystate, long long other){
	int s1 = mystate%(1LL<<13);
	int s2 = (mystate/(1LL<<13))%(1LL<<13);
	int s3 = (mystate/(1LL<<26))%(1LL<<13);
	int s4 = (mystate/(1LL<<39))%(1LL<<13);
	int a[4] = {s1, s2, s3, s4};
	int score=0;

	for (int i=0; i<4; i++){
		for (int j=i+1; j<4; j++){
			for (int k=0; k<13; k++){
				if (a[i] & a[j] & 1<<k){
					score|=(1<<k);
				}
			}
		}
	}

	 return score; 
}

int twoPair(long long mystate, long long other){
	int s1 = mystate%(1LL<<13);
	int s2 = (mystate/(1LL<<13))%(1LL<<13);
	int s3 = (mystate/(1LL<<26))%(1LL<<13);
	int s4 = (mystate/(1LL<<39))%(1LL<<13);
	int a[4] = {s1, s2, s3, s4};
	int score=0;

	int cnt=0;
	for (int i=0; i<4; i++){
		for (int j=i+1; j<4; j++){
			for (int k=0; k<13; k++){
				if (a[i] & a[j] & 1<<k ){
					cnt++;
					score|=(1<<k);
					a[i]&=~(1<<k), a[j]&=~(1<<k);
				}
			}
		}
	}
	if (cnt>=2) return score;
	else return 0;
}

int triple(long long mystate, long long other){
	int s1 = mystate%(1LL<<13);
	int s2 = (mystate/(1LL<<13))%(1LL<<13);
	int s3 = (mystate/(1LL<<26))%(1LL<<13);
	int s4 = (mystate/(1LL<<39))%(1LL<<13);
	int a[4] = {s1, s2, s3, s4};
	int score=0;

	for (int i=0; i<4; i++){
		for (int j=i+1; j<4; j++){
			for (int k=j+1; k<4; k++){
				for (int l=0; l<13; l++){
					if ( a[i] & a[j] & a[k] & 1<<l){
						score |= (1<<l);
					}
				}
			}
		}
	}
	return score;
}

int straight(long long mystate, long long other){
	int s1 = mystate%(1LL<<13);
	int s2 = (mystate/(1LL<<13))%(1LL<<13);
	int s3 = (mystate/(1LL<<26))%(1LL<<13);
	int s4 = (mystate/(1LL<<39))%(1LL<<13);
	int state = s1|s2|s3|s4;
	int score=0;

	for (int i=0; i<9; i++){
		int tmp= state/(1LL<<i)%(1<<5);
		if (tmp==31)  score|=1<<(i+4);
	}

	return score;
}

int flush(long long mystate, long long other){
	int s1 = mystate%(1LL<<13);
	int s2 = (mystate/(1LL<<13))%(1LL<<13);
	int s3 = (mystate/(1LL<<26))%(1LL<<13);
	int s4 = (mystate/(1LL<<39))%(1LL<<13);
	int a[4] = {s1, s2, s3, s4};
	int score=0;

	for (int i=0; i<4; i++){
		int cnt=0, len=0,tmpscore=0;
		while(a[i]){
			if(a[i]%2) cnt++, tmpscore=len;
			a[i]/=2, len++;
		}
		if (cnt>=5 ) score |= (1<<tmpscore);
	}
	return score;
}

int fullhouse(long long mystate, long long other){
	int s1 = triple(mystate, other);
	int s2 = onePair(mystate, other);

	int score=0;
	if (s2){
		for (int i=0; i<13; i++){
			for (int j=0; j<13; j++){
				if (i==j) continue;
				if (s1/(1<<i)%2 & s2/(1<<j)%2) score=s1;
			}
		}
	}

	return score;
}

int fourCard(long long mystate, long long other){
	int s1 = mystate%(1LL<<13);
	int s2 = (mystate/(1LL<<13))%(1LL<<13);
	int s3 = (mystate/(1LL<<26))%(1LL<<13);
	int s4 = (mystate/(1LL<<39))%(1LL<<13);
	int a[4] = {s1, s2, s3, s4};
	int score=0;

	for (int i=0; i<13; i++){
		if ( s1 & s2 & s3 & s4 & 1<<i) score|=(1<<i);
	}
	return score;
}

int straightFlush(long long mystate, long long other){
	int s1 = mystate%(1LL<<13);
	int s2 = (mystate/(1LL<<13))%(1LL<<13);
	int s3 = (mystate/(1LL<<26))%(1LL<<13);
	int s4 = (mystate/(1LL<<39))%(1LL<<13);
	int a[4] = {s1, s2, s3, s4};

	int score=0;
	for (int i=0; i<4; i++){
		for (int j=0; j<9; j++){
			int tmp= a[i]/(1LL<<j)%(1<<5);
			if (tmp==31)  score|=1<<(j+4);
		}
	}
	return score;
}
