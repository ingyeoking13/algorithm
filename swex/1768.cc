#define N 4

static int exist[10], state[1024][24], stail[1024];
static int strikball[100];

static int T=0;
typedef struct {
	int strike, ball;
} Result;

extern Result query(int guess[]);

int myQuery(int guess[]){
	Result ret = query(guess);
	if (ret.strike+ret.ball <=0 ){
		for (int i=0; i<4; i++) exist[guess[i]] = -1;
	 	return -1;
	}
	int tmp[4] = {0, 0, 0, 0};
	int st = (1<<guess[0])+(1<<guess[1])+(1<<guess[2])+(1<<guess[3]);

	for (int i=0; i<4; i++){

		tmp[i]=guess[i];
		for (int j=0; j<4; j++){
			if ( !tmp[j] ){
				tmp[j]=guess[j];

				for (int k=0; k<4; k++){
					if ( !tmp[k] ){
						tmp[k]=guess[k];

						for (int l=0; l<4; l++){
							if ( !tmp[l] ){

								tmp[l] = guess[l];
								ret=query(tmp);

								state[st][stail[st]]
									=tmp[i]*1000+tmp[j]*100+tmp[k]*10+tmp[l];

								strikball[state[st][stail[st]]] = ret.strike*10+ret.ball;
								stail[st]++;

								if ( ret.ball == 0 ) {

									int ansstate = state[st][stail[st]-1];
									for (int t= 0; t <stail[st]-1; t++){

										int tmpstate = state[st][t];


									}
									return 1;
								}
								tmp[l]=0;
							}
						}
						tmp[k]=0;
					}
				}
				tmp[j]=0;
			}
		}
		tmp[i]=0;
	}
}

void doUserImplementation(int guess[]){
	for (int i=0; i<100; i++) c[i]=0;
	for (int i=0; i<1024; i++) stail[i]=0;

	//1st
	for (int i=0; i<3; i++) guess[i]=i;
	if ( myQuery(guess) <0) for (int i=0; i<N; i++) s[i]=-1;
	
	//2nd
	for (int i=4; i<8; i++) guess[i-4]=i;
	if ( myQuery(guess) <0) for (int i=4; i<8; i++) s[i]=-1;

	//3rd
	guess[0] = 8, guess[1] =9, guess[2]=0, guess[3]=1;
	if ( myQuery(guess) <0) for (int i=8; i<12; i++) s[i%10]=-1;

	//last

}
