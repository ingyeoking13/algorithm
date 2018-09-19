#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;
struct pos{ int x, y; };
vector<pos> v;
bool chk[20];
double ans;

void dfs(int now, int cnt){
	if ( now == v.size())
	{
		if ( cnt == now/2)
		{
			long long x=0, y=0;
			int n = v.size();
			for (int i=0; i<n; i++){
				if(chk[i]) x+= (long long)v[i].x, y+= (long long)v[i].y;
				else x-= (long long)v[i].x, y-= (long long)v[i].y;
			}
			ans =min(sqrt(x*x+y*y), ans);
		}
		return; 
	}
	if ( cnt > v.size()/2) return;
	chk[now]=1;
	dfs(now+1, cnt+1);
	chk[now]=0;
	dfs(now+1, cnt);
}
int main(){
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; 
		ans=0x3f3f3f3f;
		scanf("%d", &n);
		for (int i=0; i<n; i++)
		{
			int x, y; 
			scanf("%d %d", &x, &y);
			v.push_back({x, y});
		}
		dfs(0, 0);
		printf("%.6lf\n", ans);
		v.clear();
	}
}
