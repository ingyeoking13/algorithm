//bmcho91 시간 계산 구현
//adkb 내용추가
#include <stdio.h>
#include <conio.h> // _getch()
#include <time.h> // time()
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;

void stopwatch(int onOff);
void secToHHMMSS(int secs, char* s, size_t size);
/*
int perm() {

int i = 23;
while (i > 0 && a[i] <= a[i - 1]) i--;
if (i == 0) return 0;
int j = 23;
while (a[i - 1] >= a[j]) j--;
swap(a[i - 1], a[j]);
j = 23;
while (i < j) swap(a[i], a[j]), i++, j--;
return 1;
}
*/
char timerBuffer[8 + 1]; // 06:17:20 등의 경과 시간 문자열이 저장될 버퍼 정의
int c[18] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
int comb(int n, int r) {
int i = r - 1;
while (i >= 0 && c[i] == n - r + i) i--;
if (i<0) return 0;
c[i]++;
for (int j = i + 1; j<r; j++) c[j] = c[i] + j - i;
return 1;
};
int main(void) {
for (int i = 0; i < 12; i++) a.push_back(0);
for (int i = 0; i < 12; i++) a.push_back(1);
int m = 100000;
int k = 100000;
printf("타이머 On! \n");
stopwatch(1); // 1을 인수로 넣으면 타이머가 켜짐
int i = 0;
/*	do {
//for (int i = 0; i < 24; i++) printf("%d", a[i]);
//printf("\n");

} while (perm());*/
do {
//for (int i = 0; i < 12; i++) printf("%d ", c[i]);
//printf("\n");

} while (comb(30, 15));
printf("%d", i);

stopwatch(0);
printf("타이머 OFF! 경과 시간은: [%s]\n", timerBuffer);
getchar();

return 0;
}


void stopwatch(int onOff) {
static int oldTime; // stopwatch 함수가 종료되어도 값을 기억하는 "정적 지역 변수"

if (onOff == 1) { // 타이머 켜기
oldTime = (int)time(NULL);
}

if (onOff == 0) { // 타이머 끄고, 시분초를 timerBuffer 에 저장
secToHHMMSS(
(int)time(NULL) - oldTime,
timerBuffer,
sizeof(timerBuffer)
);
}

}

void secToHHMMSS(int secs, char* s, size_t size) { // 정수로 된 초(sec)를 입력 받아, "06:17:20" 등의 형식의 문자열로 시분초를 배열에 저장
int hour, min, sec;

sec = secs % 60;
min = secs / 60 % 60;
hour = secs / 3600;

sprintf_s(s, size, "%02d:%02d:%02d", hour, min, sec);
}
