#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _n {
	char number[10];
	int len;
}NUMBER;

int mycmp(const void* a, const void* b){

	const NUMBER *sa = (const NUMBER *) a;
	const NUMBER *sb = (const NUMBER *) b;
	int dic= strcmp(sa->number, sb->number);
	return dic;
}

int main(){

	NUMBER people[100000];
	int T, num, i, j, ok;
	scanf("%d", &T);
	while(T--){
		ok=1;
		scanf("%d", &num);
		for (i=0; i<num; i++){
			scanf("%s", people[i].number);
			people[i].len = strlen(people[i].number);
		}

		qsort(people, num, sizeof(NUMBER), mycmp);

		for (i=0; i<num-1; i++){
			if(!strncmp(people[i].number, people[i+1].number, people[i].len)) {
				ok=0; break;}
		}

		if (ok) printf("YES\n");
		else printf("NO\n");
	}
}
