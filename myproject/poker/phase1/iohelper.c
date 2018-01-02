#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clrbuf(){
    while(getchar()!='\n');
}

int getIntRange(int a,  int b){
    int n=0; char c='x';
    while(a>n || b<n || c!='\n'){
        printf("Input the number between %d ~ %d  :> ", a, b);
        scanf("%d%c", &n, &c);
        if ( c!='\n') printf("** Only Integer Please! **\n"), clrbuf();
        else if (a> n || n>b) printf("** Please Input valid number ! **\n"); 
    }
    return n;
}

char* getUserName(char name[15]){
    printf("Input user name (14 characters) :> ");
    scanf("%14[^\n]", name);
    clrbuf();
    return name;
}

int yes(){
    char c=0, c2='x';
    while ( c!='Y' && c!= 'N' && c!='y' && c!='n' || c2!='\n' ){
        scanf("%c%c", &c, &c2);

        if (c2!='\n') printf("** Input please one character. **\n"), clrbuf();
        else if (c!='Y' && c!= 'N' && c!='y' && c!='n') printf("**Input Only Yy / Nn ! **\n");
    }
    return c=='y'||c=='Y';
}

void printNewTable(){
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#elif defined(__linux__)
	system("clear");
#endif
}

void printLines(const char* str){
	int len = strlen(str);
	for (int i=0; i<2; i++) printf("\n");
	for (int i=0; i<50; i++) printf("/");
	printf("\n");
	for (int i=0; i<3; i++) {
		printf("/");
		if (i!=1){
			for (int j=0; j<48; j++){
				printf(" ");
			}
		}
		else {
			for (int j=0; j<24-len/2; j++){
				printf(" ");
			}
			printf("%s", str);
			for(int j=0; j<24-len/2-(len%2); j++) printf(" ");
		}
		printf("/\n");
	}
	for (int i=0; i<50; i++) printf("/");
	printf("\n");
}

void pause(){
	printf("(Press Any key to Continue)\n");
	clrbuf();
}
