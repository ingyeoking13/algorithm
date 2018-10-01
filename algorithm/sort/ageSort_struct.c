#include <stdio.h>
#include <stdlib.h>

typedef struct _p {
size_t order;
int age;
char name[101];
}PEOPLE;

int mycmp(const void *a, const void *b) {

const PEOPLE *sa = (const PEOPLE *)a;
const PEOPLE *sb = (const PEOPLE *)b;
int age=sa->age - sb->age;
return age !=0? age: sa->order - sb->order;
}

int main() {

int i, num;
PEOPLE guest[100000];

//init
scanf("%d", &num);
for (i = 0; i<num; i++)
scanf("%d %s", &guest[i].age, guest[i].name);
for (i=0; i<num;i++)
	guest[i].order=i;

qsort(guest, num, sizeof(PEOPLE), mycmp);

for (i = 0; i<num; i++)
printf("%d %s\n", guest[i].age, guest[i].name);
return 0;
}


