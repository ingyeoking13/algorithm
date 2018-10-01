#include <stdio.h>
#define MAXLEN 1001

typedef struct{ char str[MAXLEN]; int len; }string;
int main(){

  string ori;
  for (int i=0; i<MAXLEN; i++)  ori.str[i]=0; // initialize

  fgets(ori.str, MAXLEN, stdin);

  ori.len=0;
  while( ori.str[ori.len] != '\0' )  ori.len++; // cnt to end of string == ori string length

  if ( ori.str[ori.len-1] =='\n' ){ //만약 키보드를 통해  입력파일 생성하면 newline 체크
    ori.str[ori.len-1] = '\0';
    ori.len--;
  }

  while(1){
    string from; //from 문자열 받기
    for (int i=0; i<MAXLEN; i++) from.str[i]=0; // initialize
    fgets(from.str, MAXLEN, stdin);
    from.len=0;

    while(from.str[from.len] != '\0') from.len++;
    if ( from.str[from.len-1] == '\n' ){ //입력 전처리 개행 삭제
      from.str[from.len-1]=0;
      from.len--;
    }

    if ( from.str[0] == '0' && from.str[1] == '\0') break; // 0이면 프로그램 종료

    string to; // to 문자열 받기
    for (int i=0; i<MAXLEN; i++) to.str[i] =0;
    fgets(to.str, MAXLEN, stdin);
    to.len =0;

    while(to.str[to.len] != '\0') to.len++;
    if ( to.str[to.len-1] == '\n'){
      to.str[to.len-1]=0;
      to.len--;
    }

    int matching;

    for (int i=0; i<ori.len; i++){ //original 문자열을 순회함
      matching=1;

      for (int j=0; j<from.len; j++){ //각 original문자열 인덱스마다 from 문자열 순회 O(n*m)
        if ( i+j >= ori.len) {
          matching=0;
          break;
        }
        if ( ori.str[i+j] != from.str[j] ){
          matching =0;
          break;
        }
      }
      if ( matching == 1){

        string tmp;
        for (int i=0; i<MAXLEN; i++) tmp.str[i]=0;
        tmp.len=0;

        for (int j=i+from.len; j<ori.len; j++) { //원 문장의 i+from.len ~ 부터 ori.len 까지 복사해놓음
          tmp.str[j-i-from.len] = ori.str[j];
          tmp.len++;
        }

        for (int j=0; j<to.len; j++) { //원문장을 to 문장으로 바꿈
          ori.str[i+j] = to.str[j];
        }

        for (int j=0; j<tmp.len; j++){ //원문장의 i+to.len 부터 tmp.str을 붙임.
          ori.str[i+to.len+j] = tmp.str[j];
        }

        ori.str[i+to.len+tmp.len]=0;
        ori.len -= (from.len - to.len);
        i += (to.len-1); // 반복자 i 를 점프함 to.len -1 만큼

      }
    }
    printf("%s\n", ori.str);
  }
}

