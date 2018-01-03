#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "iohelper.h"
#include "prob.h"

#if defined(__linux__)
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET "\x1b[0m"
#elif defined(_WIN32)
#include <windows.h>
#define RED     12
#define GREEN   10
#define YELLOW  14
#define BLUE    9
#define MAGENTA 13
#define CYAN    11
#define RESET   7
void setColor(int n){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}
#endif

void poker(int mode){

    long long player[8], total=0, table=0;
    int alive=0;
		srand(time(0));

    int man=getPlayer(&alive);
    hallcard(player, man, &total);
    printGame(player, man, alive, table, mode);
		printLines("1turn...");

    if(!death(player, man, &alive, table, 1, mode)) {
			printf("game over...\n");
			return ;
		}

    tableCard(3, &table, &total); //flop
    printGame(player, man, alive, table, mode);
		printLines("2turn...");

    if(!death(player, man, &alive, table, 2, mode)) {
			printf("game over...\n");
			return ;
		}

    tableCard(1, &table, &total); //turn
    printGame(player, man, alive, table, mode);
		printLines("3turn...");

    if(!death(player, man, &alive, table, 3,  mode)) {
			printf("game over...\n");
			return ;
		}

    tableCard(1, &table, &total); //river
		printGame(player, man, alive, table, mode);
		pause();
		clear();
		printLines("Winner will take it all...");
		pause();
		winner(player, man, alive, table);
		printLines("game end...");
		pause();
}

int getPlayer(int *alive){
    int ret = getIntRange(2, 8);
    for (int i=0; i<ret; i++) {
        *alive|=(1<<i);
    }
    return ret;
}

void hallcard(long long player[8], const int man, long long *total){
    for (int i=0; i<man; i++) player[i]=0;

    for (int i=0; i<man; i++){
        long long tmp = 1LL<<(rand()%52);
        long long tmp2 = 1LL<<(rand()%52);
        if (tmp==tmp2) { i--; continue; } 
        int chk=0;
        for (int j=0; j<i; j++){
            if (player[j]&tmp) chk=1;
            if (player[j]&tmp2) chk=1;
        }
        if (chk) { i--; continue; }
        player[i]=tmp|tmp2;
        *total|=tmp|tmp2;
    }
}

void printCard(long long state, int mode){

    long long tmp=state;
    for (int j=0; j<52; j++){
        if (tmp & (1LL<<j)){
					if( !mode ){
#if defined(__linux__)
							if (j<13) printf(BLUE "Spade " RESET );
							else if (j<26) printf(MAGENTA "Heart " RESET );
							else if (j<39) printf(RED "Dia " RESET );
							else printf(CYAN "Club " RESET);
#else
							if (j<13){
								setColor(BLUE); printf("Spade "); setColor(RESET);
							}
							else if (j<26){
								setColor(MAGENTA); printf("Heart "); setColor(RESET);
							}
							else if (j<39){
								setColor(RED); printf("Dia "); setColor(RESET);
							}
							else {
								setColor(CYAN); printf("Club "); setColor(RESET);
							}
#endif
						}
            int card=j%13;
            if (card != 9 && card != 10 &&
                card != 11 && card != 12){
                    printf("%d ", card+2);
            }
            else{
                if (card==12) printf("ACE ");
                else if (card==9) printf("J ");
                else if (card==10) printf("Q ");
                else printf("K ");
            } 
        }
    }
}

void printGame(long long player[8], int man, int alive, long long table, int mode){
	clear(); 
	for (int i=0; i<man; i++){
			if(alive & 1<<i){
#if defined(__linux__)
				printf(GREEN);
        printf(mode|i==0?"Player %d'":"Computer %d'" , i+1);
				printf(RESET); printf("s card :> ");
#else
				setColor(GREEN); printf(mode|i==0?"Player %d'":"Computer %d'", i+1);
				setColor(RESET); printf("s card :> ");
#endif
        printCard(player[i], 0);
        printf("\n");
			}
    }
    printf("Community card :> ");
    printCard(table, 0);
    printf("\n");
}

int death(long long player[8], int man, int* alive, long long table, int turn, int mode){

		int d=0;
    for (int i=0; i<man; i++){
			if ( *alive & 1<<i){
				printf("\n");
#if defined(__linux__)
        printf(GREEN);
			  printf(mode|i==0?"Player %d'":"Computer %d'", i+1);
			  printf(RESET); printf("s card :> " );
#else
				setColor(GREEN); printf(mode|i==0?"Player %d'":"Computer %d'", i+1);
				setColor(RESET); printf("s card :> ");
#endif
				printCard(player[i], 0);
				printf("\n");
				if (mode || i==0) calcProb(i, player, man, table, turn);
				
				if (mode || i==0){

#if defined(__linux__)
					printf(GREEN); printf("Player %d'", i+1); 
					printf(RESET); printf( "s would continue the game? [Yy/Nn] :> ");

#else
					setColor(GREEN); printf("Player %d'", i+1);
					setColor(RESET);
					printf("s would continue the game? [Yy/Nn] :> "); 
#endif
					if ( !yes()) *alive &=~(1<<i), d++;
				}
			}
    }

    printf("Total %d men dead.\n", d);
		pause();
    if (*alive) return 1;
    else {
        printf("*** All Player are dead. Game Over. ***\n");
        return 0;
    }
}

void tableCard(int n, long long *table, long long *total){
    int cnt=0;
    while(1){
        int tmp= rand()%52;
        if ( 1LL<<tmp & *total) continue;
        else{
            cnt++;
            *table |=1LL<<tmp;
            *total |=1LL<<tmp;
        }
        if (cnt==n) break;
    }
}

extern int (*func[8])(long long, long long);
extern char* str[8];

void winner(long long player[8], int man, int alive, long long table){

	for (int f=7; f>=0; f--){
		int cnt=0, max=0;
		for (int i=0; i<man; i++){
			if (alive & 1<<i){
				int tmp= func[f](player[i] | table, 0);
				if ( max< tmp ){
					max=tmp;
					cnt=1;
				}
				else if (max == tmp) cnt++;
			}
		}
		if(max && cnt==1){
			for (int i=0; i<man; i++){
				if (alive & 1<<i){
					if (max== func[f](player[i] | table, 0)){
						printf("winner is User %d ", i+1);
						printf("with ");
						printCard(max, 1);
						printf(" %s hand!!..\n", str[f]);
						printf("his hand was ...\n");
						printf("\n\n");
						printCard(player[i], 0);
						printf("\n\n");
						printf("and community card ....\n");
						printf("\n\n");
						printCard(table, 0);
						printf("\n\n");

						return;
					}
				}
			}
		}
		else if (max && cnt>1){
			for (int i=0; i<man; i++){
				if (alive & 1<<i){
					if (max== func[f](player[i] |table, 0)){
						printf("User %d ", i+1);
						printf("Draw with ");
					  printCard(max, 1);
					  printf(" %s hand!!..\n", str[f]);
						printf("his hand was ...\n");
						printf("\n\n");
						printCard(player[i] , 0);
						printf("and community card ....\n");
						printf("\n\n");
						printCard(table, 0);
						printf("\n\n");
					}
				}
			}
			return;
		}
	}
	printf("There is no pair, only top exist. no one wins...\n");
	return ;
}
