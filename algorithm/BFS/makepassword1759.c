#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len, i, word;
char al[17];

int mycmp(const void* a, const void* b){
	return (*(char *)a - *(char *)b);
}


void bfs(int l, char* password, int i){
	if(len==l){
		int ja=0, mo=0; 
		for(int i=0; i<len; i++){
			if(password[i]=='a' || password[i]=='e' || password[i]=='i' || password[i]=='o' || password[i]=='u') 
				mo++;
			else
				ja++;
		}
		if (ja>=2 && mo>=1){
			for(i=0; i<l;i++)
				printf("%c", password[i]); 
			printf("\n");
			return ;
		}
	}
	if (i>=word) return;
	char* nextpassword = password;
	nextpassword[l]=al[i];
	bfs(l+1, nextpassword, i+1);
	bfs(l, password, i+1);
}


int main(){
	char ch[17];
	scanf("%d %d", &len, &word);
	for(i=0;i<word;i++) scanf(" %c", &al[i]);
	qsort(al, word, sizeof(char), mycmp);

	bfs(0, ch, 0);

	return 0;
};

