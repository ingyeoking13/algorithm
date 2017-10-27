#include <stdio.h>

char s1[100000];
int s2[100000], t1, t2;
int main(){
	int n, chk=0; scanf("%d", &n);
	while(n--){
		char o; int num;
		scanf(" %c %d", &o, &num);

		if(o=='|'){
			if (num==1) continue;
			if(t1!=0 && s1[t1-1]=='|'){
			 	s2[t2-1]|=num; 
				if(s2[t2-1]==0) t2--,t1--;
			}
			else s1[t1++]='|', s2[t2++]=num;
		}
		else if (o=='^') {
			if(t1!=0 && s1[t1-1]=='^') {
				s2[t2-1]^=num;
				if(s2[t2-1]==0) t2--,t1--;
			}
			else s1[t1++]='^', s2[t2++]=num;
			
		}
		else if (o=='&') {
			if(t1!=0 && s1[t1-1]=='&') {
				s2[t2-1]&=num;
				if(s2[t2-1]==0) t2--,t1--;
			}
			else s1[t1++]='&', s2[t2++]=num;
		}
	}
	printf("%d\n", t2);
	int i=0;
	while(i<t2){
		printf("%c %d\n", s1[i], s2[i]);
		i++;
	}
}
