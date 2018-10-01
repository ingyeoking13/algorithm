#include <stdio.h>

int state[10];
int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<10; i++) state[i]=2;

	for (int i=0; i<n; i++){
		char ch; int tmp;
		scanf(" %c %d", &ch, &tmp);
		if(ch=='|'){
			for (int j=0; j<10; j++)
				if (tmp&(1<<j)) state[j]=1;
		}
		if (ch=='&'){
			for (int j=0; j<10; j++)
				if ((tmp&(1<<j))==0) state[j]=0;
		}
		if (ch=='^'){
			for (int j=0; j<10; j++)
				if (tmp&(1<<j)) state[j]^=1;
		}
	}

	int orv=0, xorv=0, andv=1023;
	for (int i=0; i<10; i++){
		if (state[i]==0) andv=andv-(1<<i);
		else if (state[i]==1) orv+=(1<<i);
		else if (state[i]==3) xorv+=(1<<i);
	}
	printf("3\n| %d\n& %d\n^ %d\n", orv, andv, xorv);
}

