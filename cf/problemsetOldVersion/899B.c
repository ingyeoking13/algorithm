#include <stdio.h>

int m[12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a[24];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	int ans=0; 
	for (int i=0; i<12; i++){
		int chk=0, leap=0;
		if (m[i]==a[0] || ( i==1 && (a[0]==m[i]+1 || a[0]==m[i])) ){
			int j=i; chk=1;

			for (int k=0; k<n; k++, j++){
				if (j%12!=1){
					if (m[j%12] != a[k]) { chk=0; break;}
				}
				else if ( a[k] != m[j%12] && a[k] != m[j%12]+1) { chk=0; break;}

				if (j%12 ==1 && a[k] == m[j%12]+1  && leap ) { chk=0; break;}
				if (j%12 ==1 && a[k] == m[j%12]+1) leap=1;
			}	
		}
		if (chk) ans=1;
	}
	if (ans) printf("YES\n");
	else printf("NO\n");
}
