#include <stdio.h>

using namespace std;
int t[100000],r[100000];

int main(){
	int n, m; scanf("%d %d", &n, &m);

	int k; scanf("%d", &k);

	for (int i=0; i<k; i++) scanf("%d", &t[i]);

	int cnt= n-m, ans;

	int time=0;
	while(1)
	{
		time++;
		int chk=1;
		for (int j=0; j<k; j++)
		{
			if (!r[j]) 
			{
				r[j]=t[j]; 
				cnt--;
			}
			if ( cnt == 0) {
				ans = j;
				chk=0;
				break;
			}
			r[j]--;
		}
		if (!chk) break;
	}
	printf("%d\n", ans+1);

}
