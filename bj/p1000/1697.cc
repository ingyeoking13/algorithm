/*
백준 1697
해당 문제는 BFS 기초 문제라고 생각합니다. 
수빈이가 동생을 찾기위해 탐색 하는데, 
그것을 시뮬레이션을 한다고 생각하면 됩니다. 

수빈이는 S에서 출발해서 다음엔 S+1, S-1, S*2로 이동가능합니다.
이러한 것을 반복했을 때 이전에 방문했던 곳을 방문하는 경우가 발생하지만,
최단경로 특성상 이전에 방문했던 곳을 다시 방문할 필요가 없습니다.
*/
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;
int dist[(int)1e5+1];

int main(){
	int s, e; 
	scanf("%d %d", &s, &e);
	memset(dist, -1, sizeof(dist));

	// 시작지점을 queue 에 넣습니다. 거리 배열 dist[s] = 0 으로 해줍시다. 
	// queue 의 사용방법은 구글링으로 쉽게 찾아볼 수 있습니다.
	// 대표적인 연산은 .push(), .empty(), .front() 이고,
	// 보통은 이 외에는 거의 쓸일이 없습니다.
	queue<int> q;
	q.push(s);
	dist[s] = 0;

    // queue 가 빌때까지 
	while(!q.empty())
	{
		//current
		int cur = q.front(); 
		q.pop();

		// 만약 현재 위치에서 +1 만큼 가는것이 유효하고, cur+1에 방문한적이 없다면 .. 
		// 큐에 넣고 ㅡ 거리배열을 갱신해줍니다. 
		if (cur+1 <= 100000 && dist[cur+1] == -1) q.push(cur+1), dist[cur+1]=dist[cur]+1;
		if (cur-1 >= 0      && dist[cur-1] == -1) q.push(cur-1), dist[cur-1]=dist[cur]+1;
		if (cur*2 <= 100000 && dist[cur*2] == -1) q.push(cur*2), dist[cur*2]=dist[cur]+1;
		// 위 if ()문 안에서는 A && B 형태를 볼 수 있습니다. 
		// A && B 인 경우 A가 거짓인 경우 B를 수행하지 않기때문에  ( Short circuiting 에 따라 )
		// dist[ ... ] 에서 절대 0~100,000 을 벗어나지 않습니다. 
		// 따라서 Runtime Error를 항상 피할 수 있습니다.
	}

	// queue 가 끝났을 때는, 모든 유효한 최단 경로 탐색을 끝냈다는 뜻입니다. 
	// dist에는 s(수빈의 위치) 에서부터 ~> 0~100,000 까지의 최단 거리 가 담겨져있습니다. 
	printf("%d\n", dist[e]);
}
