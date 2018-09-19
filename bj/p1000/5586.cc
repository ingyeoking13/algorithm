#include <stdio.h>
#include <string>

using namespace std;
char s[10001];
int main(){
	scanf("%s",s);
	string str =string(s);

	int now=0;
	int cnt=0;
	while((now=str.find("JOI", now))!=-1){
		cnt++;
		now++;
	}
	printf("%d\n", cnt);
	now=cnt=0;
	while((now=str.find("IOI", now))!=-1){
		cnt++;
		now++;
	}
	printf("%d\n",cnt);

}
