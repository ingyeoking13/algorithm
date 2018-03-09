#include <bits/stdc++.h>
using namespace std;

int da[100000][2], db[100000][2], cnt[2];
int main(){
    // write your code in C++14 (g++ 6.2.0)
	vector<int> A; vector <int> B;
   
	int n;  scanf("%d", &n);
	int tmp;
	for (int i=0; i<n; i++) {scanf("%d", &tmp); A.push_back(tmp);}
	for (int i=0; i<n; i++) {scanf("%d", &tmp); B.push_back(tmp);}
	
    da[0][0] = da[0][1] = A[0];
    db[0][0] = db[0][1] = B[0];
    
    for (int i=1; i<n; i++){
        da[i][0] = da[i][1] = A[i];
        db[i][0] = db[i][1] = B[i];
        if (da[i][0] <= da[i-1][0] || db[i][0] <= db[i-1][0]){
            da[i-1][0] = B[i-1], cnt[0]++;
            db[i-1][0] = A[i-1];
        }
        if (da[i][1] <= da[i-1][1] || db[i][1] <= db[i-1][1]){
            da[i][1] = B[i], cnt[1]++;
            db[i][1] = A[i];
				}
    }
    
		printf("da[i][0] ");
    for (int i=0; i<n; i++) printf("%d ", da[i][0]);
		printf("\n db[i][0] ");
    for (int i=0; i<n; i++) printf("%d ", db[i][0]);
		printf("\n da[i][1] ");
    for (int i=0; i<n; i++) printf("%d ", da[i][1]);
		printf("\n db[i][1] ");
    for (int i=0; i<n; i++) printf("%d ", db[i][1]);
		printf("\n");

    int ans=-1, chk=1;
    for (int i=1; i<n; i++){
        if ( da[i][0] <= da[i-1][0]) chk=0, printf("!!!\n");
        if ( db[i][0] <= db[i-1][0]) chk=0, printf("BBB\n");
    }

    if ( chk) ans=cnt[0];
    
    chk=1;
    for (int i=1; i<n; i++){
        if ( da[i][1] <= da[i-1][1]) chk=0, printf("QQQ\n");
        if ( db[i][1] <= db[i-1][1]) chk=0, printf("WWW %d : %d <=%d\n", i, db[i][1], db[i-1][1]);
    }
    
    if (chk && ans>0) ans= min(ans, cnt[1]);
    else if (chk) ans= cnt[1];
		printf("%d\n", ans);
}
