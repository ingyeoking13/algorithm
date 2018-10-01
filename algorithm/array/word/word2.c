#include <stdio.h>

int main(){
	char arr[5000000];
	int i, count, j=0;
	fgets(arr, sizeof(arr),stdin);

	for (i=0; arr[i]!='\n'; i++){
		if (65<= arr[i] && arr[i]<=122) j=0;
		else (
