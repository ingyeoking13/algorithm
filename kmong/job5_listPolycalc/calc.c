/*
   작성자 : gaelim (정요한)
	 수기로 다항식  입력하는것 
   struct node : 이 구조체는 정확히 한 단위의 항을 나타냅니다.
                 여기서 항이란 계수*x^(n) 이며, 예로
                 2x^3 + 3x^2 는 2항으로 이루어져있습니다.
                 node 구조체의 next 포인터 변수는 해당 항의
                 연속하는 - 다음 항의 노드 주소를 가르킵니다.
    struct poly : 이 구조체는 정확히 "항(node)" 집합의 시작과 끝 정보를
                  가지고 있습니다. 우리는 이 다항식(polynomials)구조체를
                  이용해 다항식에 접근할 겁니다.
    poly* newPoly : initialize poly
    void push(poly*, int, int) : 다항식에 num*(x^(pow)) node를 추가합니다.

    void sortPoly(poly*) : 다항식에 존재하는 node들을 pow 기준으로 정렬합니다.
                           정렬은 항과 항을 더하는 작업에서 큰 역할을 합니다.
                           PaddP의 논리구조는 암묵적으로 각 다항식의 항이
                           오름차순으로 정렬되어있다고 가정합니다.
    void printP(poly*) : 다항식에 존재하는 node들을 출력합니다.
    void PaddP(poly* dest, poly*a, poly*b):
                  이 함수는 다항식 a와 b를 더해서 새로운 dest 다항식을
                  만들어냅니다.
                  피 연산자인 두 항은 정렬이 되어있다고 가정하며,
                  각 두 항의 노드들을 순회하되, 만약 두 항의 차수가 같다면,
                  |
                  A1x^a1 + A2x^a2.. +AnX^an
                  B1x^b1 + B2x^b2.. +BnX^bn
                  |
                  위 그림에서 a1 == b1 이라면, push(dest, A1+B1,a1)을 호출하고
                  두 항의 노드 iterator를 한 단계 전진시킵니다.
                  만약 a1>b1 이라면 push(dest,A1, a1) 을 호출하고 A항의 노드
                  interator를 한 단계 전진시킵니다.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
  int num, pow;
  struct node* next;
}node;


typedef struct poly{ node* front,* tail; }poly;

poly* newPoly(){
  poly* newP = (poly*)malloc(sizeof(poly));
  newP->front=newP->tail=0;
  return newP;
};


void push(poly* now, int num, int pow){
  node* newN =  (node*)malloc(sizeof(node));
  newN->num = num; newN->pow=pow;
	newN->next=0;

  if ( !now->front){ //만약 다항식에 아무런 항이 존재하지 않는다면,
    now->front =now->tail= newN; //새로 들어온 노드는 다항식의 head이고 tail이다.
    return ;
  }
  now->tail->next=newN; //다항식에 새로운 노드는 현재 tail 노드의 다음 노드이며,
  now->tail=newN; //다항식의 tail 노드는 새로운 노드로 변경된다.
};

void sortPoly(poly* a){ //using nearly bubble
  for (node* i = a->front; i; i=i->next){
    int chk=0;
    for (node* j= a->front; j->next; j=j->next){
      if ( j->pow < j->next->pow){
        chk=1;
        int tmpn= j->num, tmpp= j->pow;
        j->pow = j->next->pow, j->num = j->next->num;
        j->next->pow = tmpp, j->next->num = tmpn;
      }
    }
    if (!chk) return;
  }
}

void printP(poly* now){
  for (node* p = now->front; p; p=p->next){
    printf("%dx^%d ", p->num, p->pow);
    if ( p->next && p->next->num>0) printf("+ ");
  }
  printf("\n");
  return ;
}

void PaddP(poly* now, poly* a, poly* b, int type){
  node* nowa = a->front, *nowb = b->front;

  while(nowa && nowb){
    int ap = nowa->pow, bp = nowb->pow;
    int an = nowa->num, bn = nowb->num;

    if (ap == bp){
			if (an+(type)*bn) push(now, an+(type)*bn, ap);
      nowa=nowa->next, nowb=nowb->next;
    }
    else if (ap > bp) push(now, an, ap), nowa=nowa->next;
    else push(now, (type)*bn, bp), nowb=nowb->next;
  }

  while(nowa) push(now, nowa->num, nowa->pow), nowa=nowa->next;
  while(nowb) push(now, (type)*(nowb->num), nowb->pow), nowb=nowb->next;
}

int makeP(poly* now, char* s){ // make polynomials from input

	int len = strlen(s), st=0, tmp=0, pm=1, coef=0; //set initial  variable

	if ('0'<= s[0]  && s[0] <='9') tmp += (s[0]-'0'); // chk if string starts with "-" or numbers
	else if (s[0]== '-') pm =-1; 

	for (int i=1; i<len; i++){ //then chk from second string
		if (st){ 								//st means state , that is input state. if st==1 we finished 상수계수 input
			if(st==1 && s[i] =='^' ) { st++; continue; } //  we get "^" from st ==1 ! state  move 2 and continue!

			if (st==2){ 									//time to get coef
				if ('0'<=s[i] && s[i] <='9'){ 
					coef*= 10;
					coef+=(s[i]-'0');
				}
				else if ( s[i] =='-' || s[i] == '+'){  // if we get another +, - then coef input is over
					push(now, pm*tmp, coef);						//push it!!
					tmp=0, st=0,coef=0;
					if (s[i] =='-' ) pm = -1;          //next ary +, - 
					else pm= 1;
				}
				else return !printf("invalid number for 다항식 차수 error\n"); //we are state 2, but invalid number
			}
			else return !printf(" invalid number for 다항식 차수 error!!!\n"); //if we are not in state 2... then error
		}
		else {   //st == 0 that means, we are taking 상수계수 input 
			if ( '0'<=s[i] && s[i]<='9'){ 
				tmp *= 10;
				tmp += (s[i]-'0');
			}
			else if ( s[i] == 'x' || s[i]=='X') st=1;  // if we get 'x', or 'X' then state -> goto 1 
			else return !printf("invalid number for 상수계수 error\n");
		}
	}

	push(now, pm*tmp, coef);

	return 1;
}

int main(){
  poly* a,* b;
  a = newPoly();
  b = newPoly();

	char s[201];
	printf("A 다항식 입력해주세요(200byte) : "); scanf("%s", s);
	if( makeP(a, s)==0) return !printf("system end\n");

  sortPoly(a); 
	printf("your A polynomials : ");
	printP(a);

	printf("B 다항식 입력해주세요(200byte) : "); scanf("%s", s);
	if( makeP(b, s) ==0) return !printf("system end\n");

	sortPoly(b);
	printf("your A polynomials : ");
  printP(b);

  poly* c = newPoly(),* d =newPoly();

  PaddP(c, a, b, 1);
	printf("your A+B = C polynomials : ");
  printP(c);

  PaddP(d, a, b, -1);
	printf("your A-B = D polynomials : ");
  printP(d);
}

