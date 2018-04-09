#include <stdio.h>
#include <stdlib.h>

#define NG 5
#define NE 4

void getir(int *n, char *s){ scanf("%d %s", n, s);}
void gete(char *s){ scanf("%s", s);}
void getg(int *n){ scanf("%d", n);}

typedef struct relat{int cn, pn; struct relat* c_next, * p_next;}relat;
typedef struct coup{int num; struct relat* head;}coup;
typedef struct pers{int num; struct relat* head;}pers;

coup* create_C(int num){ //return coupon 구조체 포인터
	coup* newC = (coup*)malloc(sizeof(coup));
	newC->num = num, newC->head = 0;
 	return newC;
}

pers* create_P(int num){ //return person 구조체 포인터
	pers* newP = (pers*)malloc(sizeof(pers));
	newP->num = num, newP->head=0;
	return newP;
}

void insert_to_C(coup* coupon, relat* nR){ //coupon 기준으로 사람번호 순으로 넣음

	relat* now= coupon->head;
	if(!now)  coupon->head=nR;
	else{
		int chk=0;
		for(;now!=coupon->head; now=now->p_next) {
			if (now->pn <nR->pn ) {
				chk=1;
				nR->p_next  = now->p_next;
				now->p_next = nR;
				break;
			}
		}
		if (!chk){
			if ( now->pn < nR->pn )  nR->p_next=now->p_next, now->p_next=nR;
			else nR->p_next=coupon->head, now->p_next=nR, coupon->head=nR;
		}
	}
}

void insert_to_P(pers* person, relat* nR){ //person 기준으로 쿠폰번호 순으로 넣음

	relat* now= person->head;
	if(!now)  person->head=nR;
	else{
		int chk=0;
		for(;now!=person->head; now=now->c_next) {
			if (now->cn <nR->cn ) {
				chk=1;
				nR->c_next  = now->c_next;
				now->c_next = nR;
				break;
			}
		}
		if (!chk){
			if ( now->cn < nR->cn )  nR->c_next=now->c_next, now->c_next=nR;
			else nR->c_next=person->head, now->c_next=nR, person->head=nR;
		}
	}
}

int insert(coup* coupon, pers* person, int cn, int pn){ //insert 호출
	relat* nR= (relat*)malloc(sizeof(relat));
	nR->c_next=nR, nR->p_next=nR;
	nR->cn = cn, nR->pn = pn;

	insert_to_C(coupon, nR); //coupon 기준 열에서 사람 번호 참조해서 알맞은곳 넣음 
	insert_to_P(person, nR); //person 기준 행에서 쿠폰 번호 참조해서 알맞은곳 넣음

	return 0;
}

int rmv(coup* coupon, pers* person, int cn, int pn){

	relat* now = coupon->head, *prev;  //coupon 기준 열에서 사람번호 참조할것

	while(now->pn!=pn) prev=now, now=now->p_next; //find relat* that has "pn"

	if ( now->p_next == now) coupon->head=0; //we find but, 쿠폰 열에 하나 쿠폰 밖에없을때
	else if ( now== coupon->head) { //we find but, 쿠폰 열에 시작하는 쿠폰일 때
		prev =now->p_next;
		while(prev->p_next != coupon->head) prev=prev->p_next;
		prev->p_next = now->p_next;
		coupon->head =now->p_next;   //
	}
	else prev->p_next = now->p_next;

	now=person->head;					//person 기준 열에서 쿠폰번호 참조할것

	while(now->cn!=cn) prev=now, now=now->c_next; //find relat* that has "cn"

	if ( now->c_next == now) person->head=0; //we find but, 사람열에 
	else if (now== person->head){
		prev = now->c_next;
		while(prev->c_next != person->head)  prev=prev->c_next;
		prev->p_next = now->c_next;
		person->head = now->c_next;
	}
	else prev->c_next = now->c_next;

	free(now);
	return 0;
}

int show_P(pers* person){
	relat* now = person->head;
	if (!now) return !printf("0\n");

	printf("%d ",now->cn);
	now=now->c_next;
	while( now!= person->head) {
		printf("%d ", now->cn);
		now=now->c_next;
	};
	printf("\n");
}

int show_C(coup* coupon){
	relat* now = coupon->head;
	if (!now) return !printf("0\n");
	printf("%c ",now->pn+'A'-1);
	now=now->p_next;
	while( now!= coupon->head) {
		printf("%c ", now->pn+'A'-1);
		now=now->p_next;
	};
	printf("\n");
}

void deepfree(coup* coupon){ //memory free~~~
	relat* now = coupon->head;
	relat* prev;
	if (!now) return;
	if ( now->p_next == now) free(coupon->head);
	else{
		while(now!= coupon->head) {
			printf("k");
			prev=now;
			now=now->p_next;
			free(prev);
			prev=0;
		}
	}
}

int main(){

	int n; char a[3], b[3];
	coup* coupon[NE+1];
	for (int i=1; i<=NE; i++) coupon[i] = create_C(i);
	pers* person[NG+1];
	for (int i=1; i<=NG; i++) person[i] = create_P(i);

	freopen("in.in","r", stdin); 

	while(1){

		scanf("%s", a);
	 	if (a[0] =='i' || a[0] == 'r'){
		 	getir(&n, b); 
			int p = b[0]-'A'+1;

			if (a[0] =='i') insert(coupon[n], person[p], n, p);
			else rmv(coupon[n], person[p], n, p);
			printf("OK\n");
		}
		else if (a[0] =='e'){
			gete(b);
			int p = b[0]-'A'+1;
			show_P(person[p]);
		}
		else if( a[0] =='g'){
			getg(&n);
			show_C(coupon[n]);
		}
		else if (a[0] =='q') break;
	}

	for (int i=1; i<= NE; i++){
	 	deepfree(coupon[i]);
		free(coupon[i]);
	}
	for (int i=1; i<= NG; i++) free(person[i]); 

}
