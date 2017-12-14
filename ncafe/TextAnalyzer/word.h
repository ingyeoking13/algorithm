#ifndef HWORD_H_
#define HWORD_H_
#include <stdio.h>

//structure declaration
typedef struct{
	char ch;
	int cnt;
}Char;

typedef struct{
	char word[51]; //each word should be less than 51 include null char
	int cnt;
}Word;

//funciont prototype Helper
int getInt();
void pause();
void clrBuf();
void printHead(const char *str);

//function prototype analyzer
FILE* getFileName(int );
void menu();
void analyzerSystem();
void alpha_count(FILE*, Char[] );
void word_count(FILE* , Word[]);
void string_find(FILE* );
void string_replace(FILE* );
int charCmp(const void*, const void*);
int wordCmp(const void*, const void*);

#endif
