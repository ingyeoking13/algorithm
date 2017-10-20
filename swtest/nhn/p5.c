#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int sex, age, no;
}person;

char s[50];
person p[1000];

int mycmp1(const void* a, const void* b){
	const struct *sa = (const struct *)a;
	const struct *sb = (const struct *)b;
	if (sa->sex>sb->sex){ return -1; }
	else if (sa->sex<sb->sex){ return 1; }
	else {


	}
}


int main(){

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int n;
	scnanf("%d", &n);

	for (int i=0; i<n; i++){
		fgets(s, 50, stdin);
		p[i].sex =s[0]-'A';
		p[i].age = atoi(s+2);
		int j;
		for (j=2; a[j]!=' '; j++);
		if (s[j+1] =='P' && s[j+2] == 'W'){ p[i].no=3; }
		else if (s[j+1] == 'P'){ p[i].no=2; }
		else if (s[j+1] == 'D' ){ p[i].no=1; }
		else p[i].no=0;
	}

	if (a==1){
		if (b==2){
			qsort(p, n, sizeof(person), mycmp1);
		}
		else{
			qsort(p, n, sizeof(person), mycmp2);
		}
	}
	else if (a==2){
		if (b==1){


		}
		else{

		}
	}
	else{
		if (b==1){


		}
		else{

		}
	}
}
