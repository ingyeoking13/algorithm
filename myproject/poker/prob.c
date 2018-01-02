#include "prob.h"

double (*func(long long, long long, int))[8]={
	onePair, twoPair, triple, straight, flush, fullhouse,
	fourCard, strightFlush
}

char* str[8]={
	"OnePair : ", "TwoPair : ", "Triple : ", "Straight : ",
	"Flush : ", "Full House : ", "Four Card : ", "Straight Flush : "
}

void calcProb(int n, long long player[8], int man, long long table , int turn){
	long long other=0;
	for (int i=0; i<man; i++){
		other|=player[i];
	}
	other|=table;
	other&=~player[n];

	long long mystate = player[n] | table;

	if (turn ==1){ 	//0 community card
		for (int i=0; i<52; i++){
			if ( !(mystate & 1LL<<i)){ //1
				long long tmp = mystate|(1<<i);
				for (int j=0; j<52; j++){
					if ( !(tmp & 1LL<<j)){ //2
						tmp |= 1LL<<j;
						for (int k=0; k<52; k++){
							if ( !(tmp & 1LL<<k)) { //3
								tmp |= 1LL<<k;
								for (int l=0; l<52; l++){
									if ( !(tmp & 1LL<<l) ) { //4
										tmp |= 1LL<<l;
										for (int m =0; m<52; m++){
											if ( !(tmp & 1LL<<m) ) {
												tmp |= 1LL<<m;

												for (int i=0; i<8; i++){
													printf("%s probability :> ", str[i]); 
													printf("%.02lf\n", func[i](tmp, other, turn));
												}

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if (turn ==2){ //3 community card
		for (int i=0; i<52; i++){
			if ( !(mystate & 1LL<<i) ){ //1
				long long tmp = mystate|(1<<i);
				for (int j=0; j<52; j++){
					if ( !(tmp & 1LL<<j) ){ //2
						tmp |=1LL<<j;
						
						for (int i=0; i<8; i++){
							printf("%s probability :> ", str[i]);
							printf("%.02lf\n", func[i](tmp, other, turn));
						}

					}
				}
			}
		}
	}	
	else if (turn ==3){ //4 community card


	}
}

double onePair(long long mystate, long long other, int turn){
	long long cnt = 0;
	for (int i=0; i<52; i++){
		if ((!(mystate & 1LL<<i)) && (!(other & 1LL<<i))) {
			for (int j=0; j<52; j++){
				if (i!=j && (!(mystate & 1LL<<j)) && (!(other & 1LL<<j))){

				}
			}
		}
	}
}
