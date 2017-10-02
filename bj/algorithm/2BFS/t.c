	#include <stdio.h>

int prime(int n)
{
	int rot=0;
		for(int nanu=2;nanu*nanu<=n;nanu++)
		{
			if(!(n%nanu)) { rot++; break; }
		}
	if(rot) return 0;
	else return 1;
}

int main(void)
{
	int num=2;
	printf("\n Prime Number : ");

	for(int rota=0;rota<10;num++)
	{
		if(prime(num)){
			printf("%d ",num);
			rota++;
		}
	}
	printf("\n");
	return 0;
}
