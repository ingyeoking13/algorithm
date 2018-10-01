#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.141592
#pragma warning(disable:4996)

int Answer;
int score[20] = { 6, 13, 4, 18, 1,20,5,12,9,14,11,8,16,7,19,3,17,2,15,10 };

int main(void)
{
int T, test_case, i, trying, j;
int arA, arB, arC, arD, arE, x, y, scre;
double degree, length;
setbuf(stdout, NULL);

scanf("%d", &T);
for (test_case = 0; test_case < T; test_case++)
{
Answer = 0;
scanf("%d %d %d %d %d", &arA, &arB, &arC, &arD, &arE);
scanf("%d", &trying);
for (i = 0; i<trying; i++) {
scanf("%d %d", &x, &y);
degree = atan2(y, x) * 180 / PI;
degree += 9;
if (degree<0) degree = 360 + degree;
j =floor(degree / 18);
scre = score[j];
length = sqrt(x*x + y*y);
if (length<arA)
Answer += 50;
else if (length<arB)
Answer += scre;
else if (length<arC)
Answer += scre * 3;
else if (length<arD)
Answer += scre;
else if (length<arE)
Answer += scre * 2;
}

printf("Case #%d\n", test_case + 1);
printf("%d\n", Answer);

}

return 0;
}
