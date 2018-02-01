#include <bits/stdc++.h>

using namespace std;
typedef struct Oper{
	string ip, o;
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
		
		cin >> op[i].o; cin >> op[i].ip;
		op[i].ip = op[i].ip.substr(0, op[i].ip.length()-1);
	}
	
	for (int i= 0; i<k; i++){
		cout << op[i].o << " " << op[i].ip << "; #" << m[op[i].ip] << "\n";
	}
}
