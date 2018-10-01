#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200;

// N: A 그룹 크기, M: B 그룹 크기
// A[i], B[i]: 각 정점이 매칭된 반대편 정점 번호
int N, M, A[MAX], B[MAX];
// adj[i]: A[i]와 인접한 그룹 B의 정점들
vector<int> adj[MAX];
bool visited[MAX];

// A그룹에 속한 정점 a를 이분 매칭시켜서 성공하면 true
bool dfs(int a){
visited[a] = true;
for(int b: adj[a]){
// 반대편이 매칭되지 않았거나
// 매칭되어 있었지만 원래 매칭되어 있던 정점을 다른 정점과 매칭시킬 수 있으면 성공
if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
A[a] = b;
B[b] = a;
return true;
}
}
// 매칭 실패
return false;
}

int main(){
scanf("%d %d", &N, &M);
for(int i=0; i<N; i++){
int S;
scanf("%d", &S);
for(int j=0; j<S; j++){
int k;
scanf("%d", &k);
adj[i].push_back(k-1);
}
}

int match = 0;
// 초기값: -1
fill(A, A+N, -1);
fill(B, B+M, -1);
for(int i=0; i<N; i++){
// 아직 매칭되지 않은 그룹 A 정점에 대해 매칭 시도
if(A[i] == -1){
// visited 배열 초기화
fill(visited, visited+N, false);
if(dfs(i)) match++;
}
}
printf("%d\n", match);
}

