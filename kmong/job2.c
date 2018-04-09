/*
	 kmong 판매자 : gaelim

	 이 작업물은 다음과 같은 개념으로 작성되었습니다.
	 1. coup 구조체는 정확히 NG+1 크기의 pers 구조체의 포인터 변수배열을 가집니다.
	 즉, coup 구조체는 다음과 같이 정의됩니다.
	 typedef struct coup{ int num; struct pers* p[NG+1];}coup;

	 여기서 num은 편의상 해당 coupon의 Id를 갖게 해주었습니다.
	 pers* p[NG+1] 배열의 각각의 원소엔 pers 구조체의 포인터 변수를 가지고 있습니다.
	 (이 점은 배열이 pers* ..[] 로 선언된것을 확인하세요.)

	 그리고 [1~NG] 의 각 각의 포인터 변수 원소들은 다음과 같이 동작합니다.
	 만약 모든 사람이 1 쿠폰을 가지고 있을때,
	 1 쿠폰의 pers* p 배열의 [1~NG]는  1~NG 번째 person의 포인터 주소를가지고 있습니다.
	 이를 그림으로 표현하면 다음과 같습니다.

	 coupon       1 
	         	/ / | \ \
	 person 	A B  C  D E 

	 따라서 우리는 임의의 coupon에 접근할 때 해당 coupon이 연결되어있는
	 모든 pers 구조체에 접근가능합니다.
	 일단은 여기까지만 설명하고 좀 더 자세한 개념은 계속 되는 기능설명에서
	 어렴풋이 이해할 수 있으실겁니다.

	 2. pers 구조체는 정확히 NE+1 크기의 coup 구조체의 포인터 변수배열을 가집니다.
	 즉, pers 구조체는 다음과 같이 정의됩니다.
	 typedef struct pers{ int num; struct coup* c[NE+1];}pers;
	 
	 여기서 num은 편의상 해당 person의 Id를 갖게 해주었습니다.
	 coup* c[NE+1] 배열의 각각 원소엔 coup 구조체의 포인터 변수를 가지고 있습니다.

	 만약 A 사람이 모든 쿠폰을 가지고 있다고 할 때 다음과 같이 표현할 수 있습니다.

	 person          A
	           /   /   \  \
   coupon		1   2     3  4

	 따라서 우리는 임의의 person에 접근할 때 해당 person이 연결되어있는
	 모든 coup 구조체에 접근가능합니다.

	 만약 모든 사람이 모든 쿠폰을 가지고 있으면 어떻게 표현할 수 있을까요?

	 A  B  C  D

   1  2  3  4  5
	 
	 우리는 그저 모든 간선을 그으면됩니다. 따라서 20개의 간선이 나올 수 있습니다.
	 20 = NG * NE이죠.

	 하지만 이 간선은 이미 정의 해두었습니다. 어디일까요?
	 간선의 역할을 하는 창구는 각각 구조체에 정의된 상대방 구조체 포인터변수입니다.
	 이미 우리는 각각 [NG+1], [NE+1] 만큼 정의했으며 사용하는 배열크기는 [1~NG], [1~NE]
	 입니다. 이해하셨나요?

	 설명은 여기까지 하고 본격적으로 구현 설명을 하겠습니다.
*/

/*
	 void get*(...,) : 이 형식의 이름을 가진  함수는 입력함수입니다.
	 [pers*,coup*] create_[CP](int num) : 이 함수는 coup 또는 pers 구조체 포인터 변수를 반환합니다.
	 int insert(coup*, pers*) : 이 함수는 pers와 coup 관계에 간선을 놓습니다.
	 	 간선 동작을 하는 것은 각각 구조체의 c[], p[] 구조체포인터배열입니다.
		 만약 해당 간선이 존재한다면 이 함수는 1을 return 하고 경고문을 띄웁니다.
		 그렇지않다면 해당 구조체 포인터 변수 배열에 상대방의 주소를 넣어줍니다.
		 coupon->p[person->num]=person; person->c[coupon->num]=coupon;

	 int rmv(coup*, pers*) : 이 함수는 pers와 coup 관계에 간선을 제거합니다.
	   이미 관계가 존재하지 않는다면 1을 리턴하여 경고를 띄웁니다.
		 만약 해당 간선이 존재한다면, 해당 포인터 변수 배열에 0을 넣습니다.
		 coupon->p[person->num]=0, person->c[coupon->num]=0;

	 void show_P(pers*) : 이 함수는 전달받은 해당 person이 가지고 있는 쿠폰을 보여줍니다.
	   for 반복문을 통해서 해당 person이 가지고 있을 c[NE+1] 만큼의 배열을 순회합니다.
		 만약 존재한다면 해당 반복자 i를 출력하면 됩니다.
	 
	 void show_C(coup*) : void show_P(pers*) 참고

*/
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

//  아래 함수를 통해 미리 작성된 input  데이터파일로
//	입력 스트림을 redirecting 할 수 있습니다.
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
