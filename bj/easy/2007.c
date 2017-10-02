#include <stdio.h>

int main(){

	int i, mon, day, ans=0;
	int arr[11]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

	scanf("%d %d", &mon, &day);
	for (i=1;i<mon;i++)
			ans+=arr[i-1];
	ans+=day;

	if(ans%7==1)
		printf("MON");
	else if(ans%7==2)
		printf("TUE");
	else if(ans%7==3)
		printf("WED");
	else if(ans%7==4)
		printf("THU");
	else if(ans%7==5)
		printf("FRI");
	else if(ans%7==6)
		printf("SAT");
	else
		printf("SUN");

	printf("\n");
  return 0;  	
}
