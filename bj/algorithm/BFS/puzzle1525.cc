#include <cstdio>
#include <queue>
using namespace std;

int facto[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int ptok(int *arr);
void ktop(int *arr, int k);
void swap(int *a, int *b);

int main(){
	int n=3, i, start=0, tmp;
	int a[9], chk[362900], dist[362900];

	for (i=0; i<9; i++){
		scanf("%d", &tmp);
		if(!tmp) a[i]=9;
		else a[i]=tmp; 
	}

	start = ptok(a);

	queue<int> que;
	dist[start]=0;
	chk[start]=1;
	que.push(start);
	while(!que.empty()){
		int now = que.front();
		que.pop();
		ktop(a, now);

		for (i=0; i<9; i++)
			if (a[i]==9)  break;  
		
		int x = i/3;
		int y = i%3;
		for (i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (nx >=0 && nx < n && ny >= 0 && ny < n){
				int nextarr[9];
				for (int j=0; j<9; j++) nextarr[j]=a[j];

				tmp = nextarr[x*3+y];
				nextarr[x*3+y] = nextarr[nx*3+ny];
				nextarr[nx*3+ny] = tmp;

				int next = ptok(nextarr);

				if(!chk[next]){
					dist[next] = dist[now]+1;
					que.push(next);
					chk[next]=1;
				}
			}
		}
	}

	if(chk[1]) printf("%d\n", dist[1]);

	else printf("-1\n");

	return 0;
}

int ptok(int *arr){
	int i, j, k=0, chk[9]={0};

	for (i=0; i<9; i++){
		for (j=1; j<arr[i]; j++){
			if (!chk[j]) k+= facto[8-i];
		}
		chk[arr[i]]=1;
	}
	return k+1;
}

void ktop(int *arr, int k){
	int i, j, chk[10]={0};

	for (i=0; i<9; i++){
		for (j=1; j<=9; j++){
			if (chk[j]) continue;
			if (facto[8-i] < k)
				k-=facto[8-i];
			else{
				arr[i] = j;
				chk[j] = 1;
				break;
			}
		}
	}
}
