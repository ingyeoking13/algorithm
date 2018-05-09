#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[50], top=-1;
int oper(char c){ return c == '/' || c=='*' || c=='+' || c=='-'; }

char* in_to_post(char* str, int len){
	char* post = (char *)malloc(len+1);
	int plen=0;

	for (int i=0; i<len; i++){
		if(oper(str[i])){
			if (str[i] =='/' || str[i] =='*' ){
				if (stack[top]=='/' || stack[top]=='*') post[plen++] =stack[top--];
				stack[++top]=str[i];
			}
			else{
				if (oper(stack[top])) post[plen++] =stack[top--];
				stack[++top]=str[i];
			}
		}
		else if (str[i]=='(') stack[++top]=str[i];
		else if (str[i]==')'){
			while(stack[top]!=')'){
				post[plen++] = stack[top--];
			}
			top--;
		}
		else post[plen++]=str[i];
	}
	while(top>=0 ){
		post[plen++] = ' ';
		post[plen++] =stack[top--];
	}
	post[plen++]=0;
	return post;
}

int eval(char* str){
	int len = strlen(str);
	int tmp=0, ans=0, chk=0;

	for (int i=0; i<len; i++){
		if (oper(str[i])){
			int a = stack[top--];
			int b = stack[top--];

			if (str[i] == '+' )  stack[++top] = b+a;
			else if (str[i] == '*' ) stack[++top] = b*a;
			else if (str[i] == '/' ) stack[++top] = b/a;
			else if (str[i] == '-' ) stack[++top] = b-a;
		}
		else if ( str[i] ==' '){
			if(chk) stack[++top]=tmp, tmp=chk=0;
		}
		else{
			tmp *= 10;
			tmp += (str[i]-'0');
			chk=1;
		}
	}
	return stack[top--];
}

int main(){
	char str[1000]; 
	fgets(str, 1000, stdin); 
	int len =strlen(str);
	if( str[len-1] =='\n') str[--len]=0;

	char* post = in_to_post(str, len);
	printf("%s\n", post);
	printf("eval of \"%s\" = %d\n", post,  eval(post));
}
