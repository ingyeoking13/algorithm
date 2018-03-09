#define N 4

typedef struct { int strike, ball ; } Result;
typedef struct { int guess[4], strike, ball; }MYGUESS ;

extern Result query(int guess[]);
MYGUESS MyGuess[100];
int MyGuessCnt = 0;
bool flag = false;

bool YesOrNo(int *guess) {
   int strike, ball;
   for (int i = 0; i < MyGuessCnt; i++) {
      ball=strike = 0;
      for (int myN = 0; myN < 4; myN++) {
         for (int comN = 0; comN < 4; comN++) {
            if (guess[myN] == MyGuess[i].guess[comN]) {
               if (myN == comN) strike++;
               else ball++;
            }
         }
      }
      if (MyGuess[i].strike != strike || MyGuess[i].ball != ball)
         return false;
   }
   return true;
}

void insert(int *guess,Result ret) {
	for (int i = 0; i < 4; i++) MyGuess[MyGuessCnt].guess[i]=guess[i];
	MyGuess[MyGuessCnt].ball = ret.ball;
	MyGuess[MyGuessCnt].strike = ret.strike;
	MyGuessCnt++;
}

bool Guess(int guess[],int cnt) {
	if (cnt == 4) {
		if (YesOrNo(guess)) {
			Result ret= query(guess);
			if (ret.strike == 4) {
				return true;
			}
			insert(guess, ret);
		}
		return false;
	}

	for (int i = 0; i < 10; i++) {
		int j;
	  for (j = 0; j < cnt; j++) {
			if (guess[j] == i) break;
	  }

	  if (j == cnt) {
			guess[cnt] = i;
			if(Guess(guess, cnt + 1)) return true;
		}
	}
	return false;
}

void doUserImplementation(int guess[]) { 
	MyGuessCnt = 0;
	flag = false;
	Guess(guess,0); 
}
