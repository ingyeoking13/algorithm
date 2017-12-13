#include <stdio.h>

int s[100000], q[100001] ,h, len, t, top=0;
char str[100000];
int main(){

	int n; scanf("%d", &n);
	for (int i=0; i<=100000; i++) q[t++]=i;

	for (int i=0; i<n; i++){
		int tmp;
	 	scanf("%d", &tmp);
		if (s[top]<tmp){
			if (q[h]<=tmp){
				do{
					top++; h++;
					s[top]=q[h]; 
					str[len++]='+';
				}while(s[top]<tmp);
			}
			else return printf("NO\n");
		}
		else if (s[top]>tmp){
			while (s[top]>tmp){
				str[len++]='-';
				top--;
			}
			if (s[top]!=tmp) return printf("NO\n");
		}
		if (s[top]==tmp)  str[len++]='-', top--;
	}
	for (int i=0; i<len; i++) printf("%c\n", str[i]);
}
