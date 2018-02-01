#include <bits/stdc++.h>

using namespace std;
typedef struct Oper{
	char ip[50], o[50];
}oper;
oper op[1000];

map<string, string> m;
int main(){
	int n, k; scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++) {
		string ip, name;
		cin >> name; cin >> ip;
		m.insert(pair<string, string>(ip, name));
	}

	for (int i=0; i<k; i++){
		scanf("%s %s", op[i].o, op[i].ip);
		op[i].ip[strlen(op[i].ip)-1]=0;
	}
	
	for (int i= 0; i<k; i++){
		cout << op[i].o << " " << op[i].ip << "; #" << m[op[i].ip] << "\n";
	}
}
