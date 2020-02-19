#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 51
int xpos[]={1,-1,0,0};
int ypos[]={0,0,1,-1};
bool vis[MAX][MAX];
int n;
char a[51][51];
int ans=1;

void check(){

	cout << "==========\n";
	for (int i=0; i<n ;i++)
	{
		for (int j=0; j<n; j++)
			cout << a[i][j];
		cout << "\n";
	}

    for(int i=0;i<n;i++){
		int cnt=1;
		for(int j=1;j<n;j++){
			if(a[i][j-1]==a[i][j]){
				cnt++;
			}else{
				if(ans<cnt)ans=cnt;
				cnt=1; 
			}
		}
        if ( ans < cnt) ans = cnt;
	}
	
	//세로체크
	 
	for(int j=0;j<n;j++){
	    int cnt=1;
		for(int i=1;i<n;i++){
			if(a[i-1][j]==a[i][j]){
				cnt++;
			}else{
				if(ans<cnt)ans=cnt; 
				cnt=1;
			}
		}
        if ( ans < cnt) ans = cnt;
	}
}

void bfs(){
	queue<pair<int,int>> q;
	q.push({0,0});
	vis[0][0]=1;

	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			 int xx=x+xpos[i];
			 int yy=y+ypos[i];
			 
			 if(xx<0 || xx>=n || yy<0 || yy>=n)continue;
			 if(vis[yy][xx])continue;
			 
            swap(a[yy][xx],a[y][x]);
            check();
            swap(a[yy][xx],a[y][x]);
            vis[yy][xx]=1;
            q.push({xx,yy});
		}
	}
}


int main(void){
	
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    cin>>n;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>a[i][j];
    	}
    }

    bfs();
    cout<<ans<<'\n';


	return 0;
}