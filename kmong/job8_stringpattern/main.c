#include <stdio.h>

char s[1001];
int main(){
	fgets(s, 1001, stdin);

	int len=0;
	while(s[len]) len++;
	if (s[len-1]=='\n') s[len-1]=0, len--;

	while(1){
		char from[1001], to[1001];
		fgets(from, 1001, stdin);

		int flen=0;
		while(from[flen]) flen++;
		if (from[flen-1] == '\n') from[flen-1]=0, flen--;

		if (from[0]=='0' && from[1]==0) return 0;

		fgets(to, 1001, stdin);

		int  tlen=0;
		while(to[tlen]) tlen++;

		if (to[tlen-1] == '\n') to[tlen-1]=0, tlen--;

		int chk;
		for (int i=0; i<len; i++){
			chk=1;
			for (int j=0; j<flen; j++){
				if ( i+j >= len)  { chk=0; break; }  // if we over the len
				if ( s[i+j]!=from[j] ) {chk=0; break; }  // if patter fault;
			}
			if (chk) { // if we find pattern ... then...

				char tmp[1001]; // it will store string that behind pattern;
				for (int j=i+flen; j<len;j++) tmp[j-i-flen]=s[j]; // [~ i+flen  string ~~~ len ~]  will be copied

				//tmplen length will be (len-i-flen)
				for (int j=0; j<tlen; j++) s[i+j] = to[j];  // [i ~ tlen] change

				// [i+tlen ~~~~~~  len-(flen-tlen)]   len - (flen -tlen) -i -tlen = (len -flen-i ==  tmplen)
				for (int j=0; j<len-i-flen; j++) s[i+tlen+j]=tmp[j];

				int diff = flen-tlen;
				len -= diff;
				s[len]=0;

				i += (flen-diff-1);
			}
		}
		printf("%s\n", s);
	}
}
