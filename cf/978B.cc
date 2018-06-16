#include <stdio.h>
#include <string>

using namespace std;
char s[101];

int main(){
	int n; scanf("%d", &n);
	scanf("%s",s);
	string str = string(s);

	int ans=0;
	while(1){

		int pos;
		if ( (pos=str.find("xxx")) >=0){
			ans++;
			str.erase(str.begin()+pos+2);
		}
		else break;
	}
	printf("%d\n", ans);

}
