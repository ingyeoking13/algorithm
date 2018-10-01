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

void poker(){

    long long player[8], total=0, table=0;
    int alive=0;
		srand(time(0));

    int man=getPlayer(&alive);
    hallcard(player, man, &total);
    printGame(player, man, alive, table);
		printLines("1turn...");
		calcProb(0, player, man, table, 1);
		pause();
    if(!death(player, man, &alive)) {
			printf("game over...\n");
			return ;
		}

    tableCard(3, &table, &total); //flop
    printGame(player, man, alive, table);
		printLines("2turn...");
		calcProb(0, player, man, table, 2);
		pause();
    if(!death(player, man, &alive)) {
			printf("game over...\n");
			return ;
		}

    tableCard(1, &table, &total); //turn
    printGame(player, man, alive, table);
		printLines("3turn...");
		calcProb(0, player, man, table, 3);
		pause();
    if(!death(player, man, &alive)) {
			printf("game over...\n");
			return ;
		}

    tableCard(1, &table, &total); //river
		printGame(player, man, alive, table);
		calcProb(0, player, man, table, 4);
		pause();
}

int getPlayer(int *alive){
    int ret = getIntRange(1, 8);
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

void printCard(long long state){

    long long tmp=state;
    for (int j=0; j<52; j++){
        if (tmp & (1LL<<j)){
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

void printGame(long long player[8], int man, int alive, long long table){
	printNewTable(); for (int i=0; i<man; i++){
			if(alive & 1<<i){
#if defined(__linux__)
        printf(GREEN "Player %d'" RESET "s card :> " , i+1);
#else
				setColor(GREEN); printf("Player %d'", i+1);
				setColor(RESET); printf("s card :> ");
#endif
        printCard(player[i]);
        printf("\n");
			}
    }
    printf("Community card :> ");
    printCard(table);
    printf("\n");
}

int death(long long player[8], int man, int* alive){
		int d=0;
    for (int i=0; i<man; i++){
			if ( *alive & 1<<i){
#if defined(__linux__)
        printf(GREEN "Player %d'" RESET "s card :> " , i+1);
#else
				setColor(GREEN); printf("Player %d'", i+1);
				setColor(RESET); printf("s card :> ");
#endif
				printCard(player[i]);
				printf("\n");

#if defined(__linux__)
				printf(GREEN "Player %d'" RESET "s would continue the game? [Yy/Nn] :> ", i+1); 
#else
				setColor(GREEN); printf("Player %d'", i+1);
				setColor(RESET);
				printf("s would continue the game? [Yy/Nn] :> "); 
#endif
				if ( !yes()) *alive &=~(1<<i), d++;
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
