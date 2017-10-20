#include <cstdio>
#include <queue>
using namespace std;
typedef struct _w{
    int Aw;
    int Bw;
}STATUS;

int cap[3];
int from[]= {0, 0, 1, 1, 2, 2};
int to[] = {1, 2, 0, 2, 0, 1};
int chk[201][201] = {{0, 0}};
int ans[201];

int main(){
    int i;
    for (i=0; i<3; i++) scanf ("%d", &cap[i]);    
    
    int sum = cap[2];
    queue<STATUS> que;
    STATUS start = {0, 0};
    que.push(start);
    chk[0][0]=1;
		ans[cap[2]]=1;

    while(!que.empty()){
        int cur[3];
        cur[0]= que.front().Aw;
        cur[1]= que.front().Bw;
        cur[2]= sum - cur[0] - cur[1];
        que.pop();
        for (i=0; i<6; i++){
            int next[3] = {cur[0], cur[1], cur[2]};
            next[to[i]] += next[from[i]];
						next[from[i]] = 0;
            if(next[to[i]]>cap[to[i]]){
                next[from[i]] = next[to[i]]- cap[to[i]];
                next[to[i]] = cap[to[i]];
            }
            if(!chk[next[0]][next[1]]){
                chk[next[0]][next[1]] = 1;
                STATUS next_s= {next[0], next[1]};
                que.push(next_s);
                if(!next[0]){
                    ans[next[2]]=1;
                } } } }
    for (i=0; i<=200; i++)
        if (ans[i]) printf("%d ", i);

    printf("\n");
    return 0;
}       
