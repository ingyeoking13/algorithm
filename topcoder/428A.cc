#include <bits/stdc++.h>

using namespace std;
class ThePalindrome{
	public:
	int find(string s){

		for (int i=0; i<s.length(); i++){

			int chk=1;
			for (int j=0; j<s.length(); j++){
				if ( i+j <s.length()-1-j){
					if ( s[i+j]!=s[s.length()-1-j] ){
						chk=0;  break;
					}
				}
			}

			if (chk) {
				return s.length()+i;
			}
		}
	}

};

int main(){
	ThePalindrome p= ThePalindrome();
	printf("%d\n",p.find("abab"));
}
