#include <stdio.h>
#define MAX 100

int main(){
	int input1, input2, input3;
  int i, j;
	char num[MAX];
  int	count[10]={0,0,0,0,0,0,0,0,0,0};

	for (i=0; i< MAX;i++){
		num[i]='a';
	}	
	scanf("%d", &input1);
	scanf("%d", &input2);
	scanf("%d", &input3);

	sprintf(num, "%lld", (long long int)input1*input2*input3);

	for (i=0;num[i]!='a';i++){
		for (j=48;j<58;j++)
			if (j==num[i]) count[j-48]++;
	}

	for (i=0;i<10;i++)
		printf("%d \n",count[i]);

	return 0;
}
