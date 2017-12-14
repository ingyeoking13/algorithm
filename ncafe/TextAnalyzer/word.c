#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word.h"

#define MAXSIZE 10000 //max size of word that can save

//---------------------------------------------//
//		     	Helper  			                     //
//---------------------------------------------//
int getInt(){
	int n; char c='x';
	scanf("%d%c", &n, &c);
	while (c!='\n' || n<=0 || n>5){
		printf("*** INVALID! *** numbers betweens 1~5 are only acceptable : ");
		if (c!='\n') clrBuf();
		scanf("%d%c", &n, &c);
	}
	return n;
}

void clrBuf(){
	while(getchar()!='\n');
}

void pause(){
	printf("(Press Enter to Continue...)\n");
	clrBuf();
}

void printHead(const char *str){
	printf("\n+-----------------------------------------------------------------------------+\n");
	printf("                      %s\n", str);
	printf("+-----------------------------------------------------------------------------+\n\n");
}

//---------------------------------------------//
//				analyzer			                    	 //
//---------------------------------------------//

FILE* getFileName(int mode){
	char input[500], str[1000];
	int chk=1;
	FILE* fp;
	while(chk){
		printf(mode?"Enter file name To Open\n":"Enter file name To Save\n");

#if defined(_WIN32) || defined(_WIN64)
		printf("*** Your OS is WINDOWS. ***\n"); 
		printf("Make sure you execute this program as an Administrator.\n");
		printf("Make sure file is in your C:\\\n");
		printf("C:\\");
		scanf("%500[^\n]", input);
		clrBuf();
		sprintf(str, "C:\\%s", input);
#elif defined(__linux__)
		printf("Make sure file is in your directories: \n");
		printf("/home/adkb/ncafe/TextAnalyzer/");
		scanf("%500[^\n]", input);
		clrBuf();
		sprintf(str, "/home/adkb/ncafe/TextAnalyzer/%s", input); 
#endif

		fp = fopen(str, mode?"r":"wt");
		if (fp) chk=0;
		else {
#if defined(_WIN32) || defined(_WIN64)
			printf("*** ERROR OCCURED *** File doesn't exist in C:\\\n\n");
#elif defined(__linux__)
			printf("*** ERROR OCCURED *** File doesn't exist in /home/adkb/ncafe/TextAnalyzer/ \n\n");
#endif
			pause();
		}
	}
	return fp;
}

void menu(){
	printf("\n=========================\n");
	printf("1. Count alphabet\n");
	printf("2. Count word\n");
	printf("3. Find word\n");
	printf("4. Replace word\n");
	printf("5. Exit\n");
	printf("=========================\n");
}

void analyzerSystem(){
	Word w[MAXSIZE];
	Char c[26];
	FILE* fp= getFileName(1); 

	int n=0;
	while(n!=5){
		menu();
		printf("Select Menu: ");
		n=getInt();
		printf("\n");

		if (n==1) alpha_count(fp, c);
		else if (n==2) word_count(fp,w);
		else if (n==3) string_find(fp);
		else if (n==4) string_replace(fp);
		if (n!=5) pause();
		fseek(fp, 0, SEEK_SET);
	}
	fclose(fp);
	printHead("System terminated...\n\n");
}

void alpha_count(FILE* fp, Char c[]){
	char ch;
	for (int i=0; i<26; i++) { // initializing
	 	c[i].ch='A'+i; 
		c[i].cnt=0;
	}

	while(~fscanf(fp, "%c", &ch)){
		if ('a'<=ch && ch<='z') c[ch-'a'].cnt++;
		else if ('A'<=ch && ch<='Z') c[ch-'A'].cnt++;
	}

	qsort(c, 26, sizeof(Char), charCmp);
	
	//show
	for (int i=0; i<26; i++){
		printf("%c : %d\n", c[i].ch, c[i].cnt);
	}
}

void word_count(FILE* fp, Word w[]){
	char str[51];
	for (int i=0; i<MAXSIZE; i++){ //initializing
		w[i].word[0] =0;
		w[i].cnt=0;
	}

	while(~fscanf(fp, "%s", str)){
		int idx=0, chk=1;
		for (idx=0; chk && idx<MAXSIZE && w[idx].word[0]; idx++){ //brute search to find same word
			if(!strcmp(w[idx].word, str)) w[idx].cnt++, chk=0;
		}
		if (idx<MAXSIZE && chk) {
			strncpy(w[idx].word, str, 51);
			w[idx].cnt++;
		}
		else if (idx>=MAXSIZE){ 
			printf("*** ERROR OCCURED *** Our Program only can save %ds word.\n", MAXSIZE);
			return ;
		}
	}

	qsort(w, MAXSIZE, sizeof(Word), wordCmp);

	//show
	for (int i=0; i<MAXSIZE; i++){
		if (w[i].word[0]) printf("%s : %d\n", w[i].word, w[i].cnt);
	}
}

int charCmp(const void* a, const void* b){
	return (*(Char *)b).cnt-(*(Char *)a).cnt;
}

int wordCmp(const void* a, const void* b){
	return (*(Word *)b).cnt - (*(Word *)a).cnt;
}

void string_find(FILE *fp){
	char tStr[51];
	printf("*** WARNING *** Make sure all words' length are less than 51 including null character.\n");
	printf("Enter finding word: ");
	scanf("%51[^\n]", tStr);
	clrBuf();
	int tLen= strlen(tStr);

	printHead("STRING FINDING RESULT");
	printf("WORD           WORD POSITION          CHAR POSITION\n\n");

	char tmp[51]; int wIdx=1, cIdx=1;
	while(~fscanf(fp, "%s", tmp)){
		int tmpLen= strlen(tmp);

		if (tLen <= tmpLen){

			for (int i=0; i+tLen<=tmpLen; i++){

#if defined(_WIN32) || defined(_WIN64)
				if (!strnicmp(tStr, tmp+i, tLen)){
#elif defined(__linux__)
				if (!strncasecmp(tStr, tmp+i, tLen)){
#endif
					printf("%s               ", tmp);
					for(int i=0; i<tmpLen; i++) printf("\b");
					printf("%13d           %12d\n", wIdx, cIdx+i); 
				}
			}

		}
		wIdx++;
		cIdx+=strlen(tmp)+1;
	}
}

void string_replace(FILE *fp){
	char tStr[51];
	printf("Enter target word: ");
	scanf("%51[^\n]", tStr);
	clrBuf();
	int tLen= strlen(tStr);

	char rStr[51];
	printf("Enter replace word: ");
	scanf("%51[^\n]", rStr);
	clrBuf();
	int rLen=strlen(rStr);

	FILE *fp2 = getFileName(0);

	int cnt=0;
	char tmp[10001], tmp2[10001];
	while(fgets(tmp, 10001, fp)){

		int tmpLen=0;
		for (int i=0; tmp[i]!='\n' && tmp[i]; i++) tmpLen++; 

		for (int i=0; i+tLen<=tmpLen; i++){

			if (!strncmp(tmp+i, tStr, tLen)){

				sprintf(tmp2, "%s", tmp+i+tLen);
				strncpy(tmp+i, rStr, rLen);
				sprintf(tmp+i+rLen, "%s", tmp2);

				tmpLen+=rLen-tLen;
				cnt++;
			}

		}

		fprintf(fp2, "%s", tmp);
	}

	fclose(fp2);
	printf("%d words are replaced\n", cnt);
}
