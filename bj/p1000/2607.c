#include <stdio.h>
#include <string.h>

char my[11]; int mylen;

int main(){
	int n; scanf("%d", &n);
	scanf("%s", my); n--;
	mylen=strlen(my);

	int ans=0;
	while(n--){
		char tmp[11]; scanf("%s", tmp);
		int tmplen = strlen(tmp);

		int al[26], bl[26]; 
		memset(al, 0, sizeof(al)); memset(bl, 0, sizeof(bl));

		for (int i=0; i<mylen; i++) al[my[i]-'A']++;
		for (int i=0; i<tmplen; i++) bl[tmp[i]-'A']++;
		for (int i=0; i<26; i++) al[i]-=bl[i]; 

		if (mylen == tmplen){

			int chk=0;
			for (int i=0; i<26; i++){
				if ( al[i]>0 ) chk+=al[i];
				else if (al[i]<0) chk-=al[i];
			}

			if (chk<=2) ans++;

		}
		else if (mylen-tmplen==1 || mylen-tmplen==-1){

			int difflen=mylen-tmplen;
			int chk=0;
			for (int i=0; i<26; i++) {
				if ( !chk && al[i]==difflen ) chk=1;
				else if ( chk && al[i]) { chk=0; break; }
			}

			if (chk) ans++;
		}
	}
	printf("%d\n", ans);
}
