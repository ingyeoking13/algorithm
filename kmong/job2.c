#include <stdio.h>
#include <stdlib.h>

#define NG 5
#define NE 4

void getir(int *n, char *s){ scanf("%d %s", n, s);}
void gete(char *s){ scanf("%s", s);}
void getg(int *n){ scanf("%d", n);}

typedef struct coup{int num; struct pers* p[NG+1];}coup;
typedef struct pers{int num; struct coup* c[NE+1]; }pers;

coup* create_C(int num){
	coup* newC = (coup*)malloc(sizeof(coup));
	newC->num = num;
	for (int i=1; i<=NG; i++) newC->p[i]=0;
	return newC;
}

pers* create_P(int num){
	pers* newP = (pers*)malloc(sizeof(pers));
	newP->num = num;
	for (int i=1; i<=NE; i++) newP->c[i]=0;
	return newP;
}

int insert(coup* coupon, pers* person){
	if (coupon->p[person->num]) return 1;
	coupon->p[person->num]=person;
	person->c[coupon->num]=coupon;
	return 0;
}

int rmv(coup* coupon, pers* person){
	if (!coupon->p[person->num]) return 1;
	coupon->p[person->num]=0;
	person->c[coupon->num]=0;
	return 0;
}

void show_P(pers* person){
	int chk=0;
	for (int i=1; i<=NE; i++) 
		if (person->c[i]) chk=printf("%d ", i);
	if (!chk) printf("0");
	printf("\n");
}

void show_C(coup* coupon){
	int chk=0;
	for (int i=1; i<=NG; i++)
		if (coupon->p[i]) chk=printf("%c ", i+'A'-1);
	if (!chk) printf("0");
	printf("\n");
}

int main(){

	int n; char a[3], b[3];
	coup* coupon[NE+1];
	for (int i=1; i<=NE; i++) coupon[i] = create_C(i);
	pers* person[NG+1];
	for (int i=1; i<=NG; i++) person[i] = create_P(i);

//	freopen("in.in","r", stdin);
	while(1){

		scanf("%s", a);
	 	if (a[0] =='i' || a[0] == 'r'){
		 	getir(&n, b); 
			pers* tmpP = person[b[0]-'A'+1];
			coup* tmpC = coupon[n];

			if (a[0] =='i') {
				if (insert(tmpC, tmpP)) 
					printf("NO. %c person already have %d coupon!\n", tmpP->num+'A'-1, tmpC->num);
				else printf("OK\n");
			}
			else {
				if (rmv(tmpC, tmpP)) 
					printf("NO. %c person do not have %d coupon.\n", tmpP->num+'A'-1,tmpC->num);
				else printf("OK\n");
			}
		}
		else if (a[0] =='e'){
			gete(b);
			pers* tmpP = person[b[0]-'A'+1];
			show_P(tmpP);
		}
		else if( a[0] =='g'){
			getg(&n);
			coup* tmpC = coupon[n];
			show_C(tmpC);
		}
		else if (a[0] =='q') break;
	}
}
