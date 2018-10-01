#include <stdio.h>

int a[3], c=1, t;
char s[100];
int main(){

	fgets(s, 100, stdin);
	int i=0;
	while(s[i]!='\n'){
		if (s[i]!=' '){
			int item=s[i]-'0';
			int chk=0;
			int j;
			for (j=0; j<3;j++){
				if (a[j]==item) { chk=1; break;}
			}
			if (chk) {
				if (j==0){
					int tmp= a[2];
					a[2]=item;
					a[0]=a[1];
					a[1]=tmp;
				}
				if (j==1){
					int tmp= a[2];
					a[2]=item;
					a[1]=tmp;
				}
			}
			else {
				if (t<3){
					a[t++]=item;
				}
				else{
					int tmp=a[0];
					a[0]=a[1];
					a[1]=a[2];
					a[2]=item;
					c=0;
					printf("%d\n", tmp);
				}
			}
		}
		i++;
	}
	if (c) pinrtf("0\n");
}
