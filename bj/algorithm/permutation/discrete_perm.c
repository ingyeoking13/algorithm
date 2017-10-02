#include <stdio.h>
#include <stdlib.h>
#define P(n,r) (facto(nElmnt)/facto(nElmnt-rSize))
#define C(n,r) (facto(nElmnt)/(facto(nElmnt-rSize)*facto(rSize)))

void permutation(int, int, int**);
void combination(int, int, int**);
void show(int, int, int**);
int facto(int);

int main() {
//**** PART 1, Declare and Allocation
int nElmnt, rSize, i;
int **n_C_r;

printf("@ n의 값을 입력 하세요 : ");
scanf("%d", &nElmnt);
printf("@ r의 값을 입력 하세요 : ");
scanf("%d", &rSize);

//***** Dynamic Memory Allocation
n_C_r = (int**)malloc(C(nElmnt,rSize)*sizeof(int*));
for (i = 0; i < C(nElmnt, rSize); i++)
n_C_r[i] = (int*)malloc(rSize * sizeof(int));

//***** Array Initialize
for (i = 0; i < rSize; i++)
n_C_r[0][i] = i + 1;

//**** PART 2, Call Function
combination(nElmnt, rSize, n_C_r);
printf("원소의 %d-조합(총%d개) : ", rSize, C(nElmnt, rSize));
show(nElmnt, rSize, n_C_r);

printf("원소의 %d-순열(총%d개) : ", rSize, P(nElmnt, rSize));
permutation(nElmnt, rSize, n_C_r);
printf("\n");
return 0;
}

void permutation(int nElmnt, int rSize, int** n_P_r) {
#define swap(a, b, c){temp = n_P_r[a][b]; n_P_r[a][b] = n_P_r[a][c]; n_P_r[a][c] =temp;}

int l=0, j, q, k, temp;

while (1) {

for (j = 0; j < rSize; j++) {
printf("%d", n_P_r[l][j]);
j < rSize - 1? printf(""): printf(", ");
}

for (j = rSize - 1; j&& n_P_r[l][j - 1] >= n_P_r[l][j]; j--);
if (!j--) {
if (l == C(nElmnt, rSize) - 1)
return;
else {
l++;
continue;
}
}

for (q = rSize - 1; n_P_r[l][q] <= n_P_r[l][j]; q--);

swap(l, j, q);

for (j++, q = rSize - 1; q > j; q--, j++)
swap(l, j, q);

continue;
}
#undef swap
}

void combination(int nElmnt, int rSize, int** n_C_r) {

int i=0,j;

while (1) {

i++;
if (i >= C(nElmnt, rSize)) return;
for (j = 0; j < rSize; j++)
n_C_r[i][j] = n_C_r[i - 1][j];

for (j = rSize - 1; n_C_r[i][j] >= nElmnt - (rSize - 1 - j);j--);

for (n_C_r[i][j]++; j<rSize - 1; j++) n_C_r[i][j + 1] = n_C_r[i][j] + 1;
}
}

int facto(int n) {

int f = 1;
int i;

for (i = 1; i <= n; i++) f *= i;

return f;
}

void show(int nElmnt, int rSize, int** n_C_r) {
int i, j;
for (i = 0; i < C(nElmnt, rSize);i++)
for (j = 0; j < rSize; j++) {
printf("%d", n_C_r[i][j]);
j < rSize-1 ? printf("" ):i<C(nElmnt, rSize)-1? printf(", ") : printf("\n");
}
}

