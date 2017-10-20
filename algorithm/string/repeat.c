#include <stdio.h>

int main(){

	int i, j, num, T, t_case;
	char str[21];

	scanf("%d", &t_case);
	for (T=0; T<t_case; T++){
		for (i=0; i<21;i++) str[i]='\0';
		scanf("%d %s", &num, str);

		for(i=0; str[i]; i++)
			for (j=0; j<num; j++)
				printf("%c", str[i]);
		printf("\n"); 
	}

	return 0;
}
