#include <bits/stdc++.h>

using namespace std;
int a[200001], l[200001], r[200001];
char s[2000001];

int main(){
	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]); 
		a[i]=a[i]-i;
	}


	scanf("%s", s);
	int len= strlen(s);

	for (int i=1; i<n; i++){
		if (s[i-1]-'0') l[i]+=l[i-1]+1;
	}

	for (int i=n-2; i>=0; i--){
		if (s[i]-'0') r[i]+=r[i+1]+1;
	}


	for (int i=1; i<=n; i++){
		if (a[i]>0 && a[i]<=r[i-1]) a[i]=0;
	}


	for (int i=1; i<=n; i++){
		if (a[i]<0 && abs(a[i])<=l[i-1]) a[i]=0;
	}

	printf("\n");
	int ans=0;
	for (int i=1; i<=n;  i++) if(a[i]) ans=1;
	printf(ans?"NO\n":"YES\n");

}
