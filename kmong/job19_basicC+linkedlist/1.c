#include <stdio.h>
/******************************/

/* 판매량 검색프로그램 1.0    */

/******************************/
 

/* 첫번째 요소 : 4 지점 (서울,부산,인천,광주)
   두번째 요소 : 3 품목(컴퓨터,프린터,스캐너)
   세번째 요소 : 4분기(1/4분기, 2/4분기, 3/4분기, 4/4분기)
 */

int sale[4][3][4] = {
	{ { 10, 20, 15, 30 }, {5,8,40,50},{ 26,12,18,27 }},
	{{ 8,22,7,3 },{25,23,43,20}, { 6,13,28,17 }},
	{{ 15,29,6,23 }, {25,8,15,20}, { 36,23,36,21 }}
};

char division[4][10] = { "서울", "부산", "인천", "광주" };
char product[3][10] = { "컴퓨터", "프린터", "스캐너" };
char quarter[4][10] = { "1/4", "2/4", "3/4", "4/4" };

/* 함수를 미리정의 함으로써 함수의 위치를 자유롭게 할 수 있다*/

int menu(void);
void all_sales(void), division_sales(void), product_sales(void), quarter_sales(void);
void separte_sales(void), division_ave_sales(void), update_sales(void);
void clrbuf(){ while(getchar()!='\n'){} };

int get_division(){
	printf("지점을 번호를 입력하세요(1.서울 2.부산 3.인천 4.광주): ");
	int choice = getchar() - '0';
	clrbuf(); choice--;
	return choice;
}
int get_quarter(){
	printf("분기를 입력하세요(1. 1분기 2. 2분기 3. 3분기 4. 4분기): ");
	int choice = getchar() - '0'; //사용자가 입력한 아스키 문자를 정수로 저장
	clrbuf();
	choice--;
	return choice;
}
int get_product(){
	printf("제품 번호를 입력하세요(1.컴퓨터 2.프린터 3.스캐너): ");
	int choice = getchar() - '0'; //사용자가 입력한 아스키 문자를 정수로 저장
	clrbuf(); choice--;
	return choice;
}

void main(void)
{
	int choice;
	do {
			choice = menu(); //선택한 메뉴를 치환
			switch(choice){
				case 1: all_sales(); // 전체 판매량 검색
					break;
				case 2: division_sales(); // 지점별 판매량 검색
					break;
				case 3:product_sales(); // 제품별 판매량 검색
					break;
				case 4: quarter_sales(); //분기별 판매량 검색
					break;
				case 5: separte_sales(); // 특정 지점, 특정 제품 , 특정분기에서 판매량
							break;
				case 6:division_ave_sales(); // 지점별 전체 제품에 대한 분기당 평균 판매량
						break;
				case 7: update_sales(); //특정 지점, 특정제품, 특정분기에서 판매량 갱신
					break;
		}
		printf("\n");
	} while (choice != 8);
}
//사용자가 메뉴를 선택하여 선택한 번호를 반환하는 함수

int menu(void)
{
	int i;

	printf("\n============================== \n");
	printf("판매량 검색 프로그램\n");
	printf("1.전체 판매량 검색\n");
	printf("2.지점별 판매량 검색\n");
	printf("3.제품별 판매량 검색\n");
	printf("4.분기별 판매량 검색\n");
	printf("5.지점별, 제품별, 분기별 판매량 검색\n");
	printf("6.지점별 분기당 평균 판매량\n");
	printf("7.판매량 갱신\n");
	printf("8.종료\n");
	printf("\n============================== \n");

	do {
		printf("번호를 선택하세요: ");
		i = getchar() - '0'; //사용자가 입력한 아스키 문자를 정수로 저장
		clrbuf();
		printf("\n");
	} while (i < 1 || i>8); //1부터 5까지만 입력하게 함

	return i; // 사용자가 선택한 메뉴 번호를 반환
}

void all_sales(void) {
	int i, j, k, sum = 0;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 4; k++)
				sum = sum + sale[i][j][k];

	printf("올해 판매한 전지점의 전체 제품수는 %d개 입니다\n", sum);
}

void division_sales(void)
{
	int i, j, choice;
	int sum = 0;

	   //검색할 지점을 입력
	printf("지점을 번호를 입력하세요(1.서울 2.부산 3.인천 4.광주): ");
	choice = getchar() - '0'; //사용자가 입력한 아스키 문자를 정수로 저장
	clrbuf();
	choice--;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			sum = sum + sale[choice][i][j];

	printf("올해 %s 지점에서 판매한 전체 제품수는 %d개 입니다\n", division[choice], sum);

}

void product_sales(void) {
	int i, j, choice;
	int sum = 0;

           //검색할 제품을 입력
	printf("제품 번호를 입력하세요(1.컴퓨터 2.프린터 3.스캐너): ");
	choice = getchar() - '0'; //사용자가 입력한 아스키 문자를 정수로 저장
	clrbuf();
	choice--; //제품번호를 배열의 인덱스로 바꾼다

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			sum = sum + sale[i][choice][j];

	printf("올해 %s 제품의 판매량 %d개 입니다\n", product[choice], sum);
}

void quarter_sales(void) {
	/* 전체 지점에서 특정 분기에 판매된 전체 판매량 구하기 */
	int d =get_division(), q =get_quarter();

	int sum=0;
	for (int i=0; i<3; i++){
		sum+=sale[d][i][q];
	}
	printf("%s 지점 %s 분기 총 판매량은 %d입니다.\n", division[d],quarter[q], sum);
 
}

void separte_sales(void) {
	/* 특정 지점, 특정 제품, 특정 분기를 사용자에게 묻고 판매량 구하기 */
	int d = get_division(), q = get_quarter(), p = get_product();

	printf("%s 지점 %s 분기 %s 제품 판매량은 %d 입니다.\n", 
			division[d], quarter[q], product[p], sale[d][p][q]);
}

void division_ave_sales(void) {
/* 지점별 전체 제품에 대한 분기당 평균 판매량 */
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			int sum=0;
			for (int k=0; k<3; k++){
				sum+=sale[i][k][j];
			}
			printf("%s 지점 %s 분기 제품 평균 판매량 %d 입니다\n", 
					division[i], quarter[j], sum/3);
		}
	}
}

void update_sales(void) {
	/* 특정 지점, 특정 제품, 특정 분기를 선택하게하고 현재 판매량을 출력후 새로운 값을 입력 받고 갱신한다 */

	int d = get_division(), q = get_quarter(), p = get_product();

	printf("%s 지점 %s 분기 %s 제품 판매량을 기입해주세요.\n",
			division[d], quarter[q], product[p]);
	int n;
	scanf("%d", &n);
	clrbuf();

	sale[d][p][q]=n;
}
