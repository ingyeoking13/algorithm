#include <bits/stdc++.h>

map<pair<string, int> > d;

int canbepalin(int now){
	int a[10];
	for (int i=0; i<10; i++) a[i]=0;

	while(now){
		a[now%10]++;
		now/=10;
	}

	int chk=1;
	for (int i=0; i<10; i++){
		if ( a[i]%2==1) chk=0;
	}
	return chk;
}

int len(int now){
	int ret=0;
	while(now) {now/=10; ret++;}
	return ret;
}

int main(){

	int palin=11;
	for (int i=11; i<=200000; i++){
		d[i]=palin;

		if(canbepalin(i)) palin=i;
	}

	int T; scanf("%d", &T);
	while(T--){
		int tmp;
		scanf("%d",&tmp);
		printf("%d\n", d[tmp]);
	}
}
