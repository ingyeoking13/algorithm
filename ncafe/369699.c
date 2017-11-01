#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
int x = 0, y = 0;
int oldx = 0, oldy = 0;
int checkboard[38][38];
int player = 1;
char stone[3][3] = { "","○","●" };
char stone2[2][2] = { "","⊙" };
void gotoxy(int, int);
void draw();
void move();
void check_and_result(int);
int main()
{
system("mode con:cols=40 lines=40");
CONSOLE_CURSOR_INFO A;
A.dwSize = 1;
A.bVisible = FALSE;
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &A);
draw();
while (1)
{
move();
}
return 0;
}
void move()
{

char input = 0;
input = _getch();
switch (input)
{
case UP:
if (y>0 && y <= 18)
{
y -= 1;
oldy = y + 1;
gotoxy(x, y);
puts("⊙");
gotoxy(x, oldy);

if (checkboard[oldy][x]<1)
{
if (oldy == 18)
{
if (x == 0)
{
puts("└");
}
if (x == 36)
{
puts("┘");
}
else if (x != 0 && x != 36)
{
puts("┴");
}
}
else if (x == 0)
{
puts("├");
}
else if (x == 36)
{
puts("┤");
}
else
{
puts("┼");
}
}
else if (checkboard[oldy][x] == 1) puts("○");
else puts("●");
}
break;
case DOWN:
if (y<18 && y >= 0)
{
y += 1;
oldy = y - 1;
gotoxy(x, y);
puts("⊙");
gotoxy(x, oldy);

if (checkboard[oldy][x]<1)
{
if (oldy == 0)
{
if (x == 0)
{
puts("┌");
}
if (x == 36)
{
puts("┐");
}
else if (x != 0 && x != 36)
{
puts("┬");
}
}
else if (x == 0)
{
puts("├");
}
else if (x == 36)
{
puts("┤");
}
else
{
puts("┼");
}
}
else if (checkboard[oldy][x] == 1) puts("○");
else puts("●");
}
break;
case RIGHT:
if (x >= 0 && x<36)
{
x += 2;
oldx = x - 2;
gotoxy(x, y);
puts("⊙");
gotoxy(oldx, y);

if (checkboard[y][oldx]<1)
{
if (oldx == 0)
{
if (y == 0)
{
puts("┌");
}
if (y == 18)
{
puts("└");
}
else if (y != 0 && y != 18)
{
puts("├");
}
}
else if (y == 0)
{
puts("┬");
}
else if (y == 18)
{
puts("┴");
}
else
{
puts("┼");
}
}
else if (checkboard[y][oldx] == 1) puts("○");
else puts("●");
}
break;
case LEFT:
if (x <= 36 && x>0)
{
x -= 2;
oldx = x + 2;
gotoxy(x, y);
puts("⊙");
gotoxy(oldx, y);

if (checkboard[y][oldx]<1)
{
if (oldx == 36)
{
if (y == 0)
{
puts("┐");
}
if (y == 18)
{
puts("┘");
}
else if (y != 0 && y != 18)
{
puts("┤");
}
}
else if (y == 0)
{
puts("┬");
}
else if (y == 18)
{
puts("┴");
}
else
{
puts("┼");
}
}
else if (checkboard[y][oldx] == 1) puts("○");
else puts("●");
}
break;
case ENTER:
if (checkboard[y][x] == 0)
{
if (player % 2 == 1)
{
checkboard[y][x] = player;
gotoxy(x, y);
puts("○");
check_and_result(player);
player = 2;
}
else
{
checkboard[y][x] = player;
gotoxy(x, y);
puts("●");
check_and_result(player);
player = 1;

}
}
}
}
void gotoxy(int a, int b)
{
COORD Pos = { a,b };
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void draw()
{
char a[39][39] =
{
"┌┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┐",
"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
"└┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┘"
};
int count;
printf("%s\n", a[0]);
for (count = 0; count<17; count++)
printf("%s\n", a[1]);
printf("%s", a[2]);
printf("\n");
printf("           **오목 게임**\n"
"1.방향키를 움직여 게임을 시작하세요.\n"
"2.돌을 놓는방법은 엔터를 입력하세요.\n"
"3.검정색 돌부터 진행됩니다.\n");
}
void check_and_result(int p){

int chk = 0;
//세로
for (int i = 0; i < 5; i++) {
if (y-4+i>=0 && y+i<=18){
if (checkboard[y - 4 + i][x] == p && checkboard[y -3 + i][x] == p && checkboard[y -2 + i][x] == p && checkboard[y - 1 + i][x] == p && checkboard[y + i][x] == p)
chk = 1;
}
}
//가로
for (int i = 0; i < 10; i+=2) {
if (x - 8 + i >= 0 && x + i <= 36) {
if (checkboard[y][x-8+i] == p && checkboard[y][x-6+i] == p && checkboard[y][x-4+i] == p && checkboard[y][x-2+i] == p && checkboard[y][x+i] == p) 
chk = 1;
}
}

//오른위대각선
for (int i = 0; i < 5; i++) {
if (y-i>=0 && x-8+2*i>=0 && y+4-i<=18 && x+2*i<=36){
if (checkboard[y+4-i][x-8+i*2] == p && checkboard[y+3-i][x-6+i*2] == p && checkboard[y+2-i][x-4+i*2] == p && checkboard[y+1-i][x-2+i*2] == p && checkboard[y-i][x+i*2] == p) 
chk = 1;
}
}
//왼쪽위대각선
for (int i = 0; i < 5; i++) {
if (y- i >=0 && x-i>=0 && y+4-i<=18 && x+8-2*i<=36) {
if (checkboard[y-i][x-2*i] == p && checkboard[y+1-i][x+2-i*2] == p && checkboard[y+2-i][x+4-2*i] == p && checkboard[y+3-i][x+6-2*i] == p && checkboard[y+4-i][x+8-2*i] == p) 
chk = 1;
}
}
if (chk)
{
system("cls");
if (player == 1)printf("흑승리");
else printf("백승리");
getchar();
exit(0);
}
}
