#include <stdio.h>

int a[3] ={1, 2, 3};
int b[3] ={4, 5, 6};
int c[3] ={7, 8, 9};
int* d[3]={a, b, c};


unsigned char fndDataArray[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x67 }; // 공통 캐소드
unsigned char fndSelectArray[4] = { 0x01, 0x02, 0x04, 0x08 };

unsigned char studentNumberLow[4] = { fndDataArray[1], fndDataArray[6], fndDataArray[0], fndDataArray[2] };
unsigned char studentNumberMiddle[2] = { fndDataArray[1],fndDataArray[1] };
unsigned char studentNumberHigh[4] = { fndDataArray[4], fndDataArray[1], fndDataArray[0], fndDataArray[2] };
unsigned char *studentNumberArr[3] = { studentNumberHigh, studentNumberMiddle, studentNumberLow };

int main(){

	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			printf("%d ", d[i][j]);

		}
		printf("\n");

	}
};
