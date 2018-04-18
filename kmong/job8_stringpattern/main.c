/*
	 각 단어로 수정되면 그만큼 뒤에 따라오는 문자열 뒤로 밀어줘야하고
	 짧은 단어가 들어오면 뒤에 따라오는 문자열 그만큼 땡겨줘야함
	 이 작업이 굉장히 귀찮다. [  -----스트링------- ] 이 있으면 이게 막
	 [ -                  -   -   -스트링  -               -   -   ] 이렇게 되기도하고
	 [ --스트링--]  이런 식으로 되기도 하는거다. 한번의패턴 변환때..
	 이 방법이 귀찮은점은 한 스트링의 i, j 를 이리저리 왔다갔다하면 아무리 잘해도 버그 투성이일거같다.

	 그래서 조금 다르게 생각하여 , 각 단어를 개별적으로 관리해줘서 그 뒤에 합쳐주면 어떨까?
	 [단어] [단어] [단어] [단어] 이런식이 잇으면 바뀐것만 바꿔주고
	 [단어] [단어*] [단어*] [단어]   길이는 어쨌든 1000 이하일테니까 (1001은 null 바이트포함해야함)
	 그걸 출력할때는 인의적으로 출력하여 마치 하나의 스트링처럼 보이게할 수 있을것이다.
	 자료구조를 쓰면 좀더 멋질 수 있겠지만 진도에 맞춰서 작성해야하기때문에 이렇겧한다.

*/
#include <stdio.h>

char s[1001][1001], chk[1001];
int slen[1001];
int main(){
	int word=0;
	while(~scanf("%s", s[word++])); // 단어 만큼 받는다. human interface 사용땐 EOF 구현은 ctrl+d (리눅스 기준)
	
	/*
	for (int i=0; i<word; i++){ // 잘 받았는지 확인.
		printf("%s\n", s[i]);
	}
	*/

	for (int i=0; i<word; i++){
		int len=0;
		while(s[len]) len++; //retrieve len
		slen[i]=len;
	}

	// now we get pattern change query
	char from[1001], tmp[1001];
	int state=1;
	while(~scanf("%s", tmp)){ // if scanf fail then return 1(0xFFFFFFFF) and its ~(complement) is 0

		if (state==1){ // if we state 1 then we have to get from...pattern

			int tmplen =0;
			while(tmp[tmplen]) tmplen++;

			for (int i=0; i<word; i++){ // each word chk;

				int mat;
				for (int j=0; j<slen[i]; j++){ // now we are going to pattern matching  
					mat=1;

					for (int k=0; k<tmplen; k++){
						if ( j+k >= slen[i]) { chk=0; break; } // if i+j is  over it's len
						if ( s[i][j+k] != tmp[j]) { chk=0; break; }  // if s[i+j] ! = tmp[j], then pattern fault
					}

					if (mat) {   // if chk is true, then we find correct pattern.
						j+= (tmplen-1); // then we need to jump ~> because we dont want to find another pattern 
														// in it !. 
						chk[i]=1; // 일단 찾았다면, 여기 단어는 바꿀게 있다고 해놓는다.
										  // 나중에 이게 연산도를 떨어뜨리는데 도와줄것이다.
					}
				}

			}
			for (int i=0; i<tmplen; i++) from[i]= tmp[i]; // 그리고 패턴 문자열을 딴 배열에 저장해놓음.
			state = 3-state;
		}
		else{  //state 가 2라면... 
			int tmplen=0;
			whilie(tmp[tmplen]) tmplen++;

			for (int i=0; i<word; i++){ //각 단어는... 
				if ( !chk[i] ) continue;   // 바뀐적이 없으면 넘어감!

				for (int j=0; j<










			}

			state = 3-state;
		}
	}

}
