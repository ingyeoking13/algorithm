#include <cstdio>
#include <stack>

using namespace std;
char input[10000];
char out[10000];
int main(){

	int i=0, j=0;
	stack<char> adkb;
	scanf("%s", input);
	while(char temp=input[i++]){
		if (temp=='\0') break;
		else if (temp=='(') adkb.push(temp);
		else if (temp==')') {
			while(adkb.top()!='('){
				char temp2=adkb.top();
				adkb.pop();
				out[j++]=temp2;
			}
			adkb.pop();
		}
		else if (temp=='+' || temp=='-'){
			while(!adkb.empty()){
				char temp2= adkb.top();
				adkb.pop();
				if(temp2=='+' || temp2=='-' || temp2=='*'|| temp2=='/')
				{out[j++]=temp2;}
				else {adkb.push(temp2); break;}
			}
			adkb.push(temp);
		}
		else if (temp=='*' || temp=='/'){
			if(!adkb.empty()){
				char temp2=adkb.top();
				adkb.pop();
				if(temp2=='*'|| temp2=='/')
					out[j++]=temp2;
				else adkb.push(temp2);
			}
			adkb.push(temp);
		}
		else{
		  out[j++]=temp;
		}
	}
	while(!adkb.empty()){
		out[j++] = adkb.top();
		adkb.pop();
	}
	printf("%s\n", out);
}
