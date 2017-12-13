#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count=0;
bool primising(int level,int cols[]);
void nQueen(int level,int cols[]);
int main(){
	int num=0;//testcase
	int arr[50], cols[50];
	scanf("%d",&num);

	count=0;
	nQueen(0,cols);
	printf("%d\n",count);
}
bool promising(int row,int *cols){
	for(int k=0;k<row;k++){
		if(cols[k]==cols[row]){
			return false;
		}
		else if(row-k==abs(cols[row]-cols[k])){
//			printf("row %d : %d %d\n", row,  k,  cols[k]);
			return false;
		}
	}
	return true;
}
void nQueen(int row,int *cols){     
	if(!promising(row-1,cols)) return ; 
	else if(row==num){
		count++;
	}
	else{
		for(int j=0;j<num;j++){
			cols[row]=j;
//			printf("%d %d %d\n", row, a, cols[row]);
			nQueen(row+1,cols,a);
		}
	}
}
