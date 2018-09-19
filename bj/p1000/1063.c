#include <stdio.h>
char sk[3], st[3], s[3];
int dx[8]={1, -1, 0, 0, 1, -1, 1, -1};
int dy[8]={0, 0, -1, 1, 1, 1, -1, -1};
int main(){
	int a; scanf("%s", sk); scanf(" %s ", st);
	int kx=sk[0]-'A', ky=sk[1]-'1'; int sx=st[0]-'A', sy=st[1]-'1';
	int n; scanf("%d", &n);
	while(n--){
		int tmp;
		scanf("%s", s);
		if (s[0]=='R' && s[1]=='T'){
			if (kx+dx[4]>7 || ky+dy[4]>7) continue;
		 	kx+=dx[4], ky+=dy[4], tmp=4;
		}
		else if (s[0]=='L' && s[1]=='T') {
			if (kx+dx[5]<0 || ky+dy[5]>7) continue;
		 	kx+=dx[5], ky+=dy[5], tmp=5;
		}
		else if (s[0]=='R' && s[1]=='B'){
			if (kx+dx[6]>7 || ky+dy[6]<0) continue;
		 	kx+=dx[6], ky+=dy[6], tmp=6;
		}
		else if (s[0]=='L' && s[1]=='B') {
			if (kx+dx[7]<0 || ky+dy[7]<0) continue;
			kx+=dx[7], ky+=dy[7], tmp=7;
		}
		else if (s[0]=='R'){
			if (kx+dx[0]>7 ) continue;
		 	kx+=dx[0], tmp=0;
		}
		else if (s[0]=='L'){ 
			if (kx+dx[1]<0 ) continue;
			kx+=dx[1], tmp=1;
		}
		else if (s[0]=='B'){ 
			if (ky+dy[2]<0 ) continue;
			ky+=dy[2], tmp=2;
		}
		else if (s[0]=='T') {
			if (ky+dy[3]>7) continue;
			ky+=dy[3], tmp=3;
		}
		if (kx== sx && ky== sy) {
			if (0<=sx+dx[tmp] && sx+dx[tmp]<=7 &&
					0<=sy+dy[tmp] && sy+dy[tmp]<=7) sx+=dx[tmp],sy+=dy[tmp];
			else kx-=dx[tmp], ky-=dy[tmp];
		}
	}
	printf("%c%c\n", kx+'A', ky+'1'); printf("%c%c\n", sx+'A', sy+'1');

}
