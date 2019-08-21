#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;
const int INF = 987654321;
int N, M;
int board[MAX_N + 1][MAX_N + 1]; //time, y , x
enum { WALL = -1, BLANK };
int startX, startY;
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };
vector <pair<int, int>> fire; //불 시발점의 좌표

bool isinboard(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

// 시간에 따른 board변화를 저장
void getboard()
{
	bool tvisited[MAX_N + 1][MAX_N + 1] = { 0, };
	queue <pair<int, int>> q;
	for (auto i : fire)
	{
		q.push(i);
		tvisited[i.first][i.second] = 1;
		board[i.first][i.second] = 1;
	}

	while (!q.empty())
	{
		int nowY = q.front().first, nowX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i], nextX = nowX + goX[i];
			if (isinboard(nextY, nextX) && board[nextY][nextX] != WALL && !tvisited[nextY][nextX])
			{
				tvisited[nextY][nextX] = 1;
				board[nextY][nextX] = board[nowY][nowX] + 1;
				q.push(make_pair(nextY, nextX));

			}
		}
	}

}

void  bfs()
{
	int visited[MAX_N + 1][MAX_N + 1] = { 0, };
	int minDist = INF;
	queue <pair<int, int>> q;
	q.push(make_pair(startY, startX));
	visited[startY][startX] = 1;
	while (!q.empty())
	{
		int nowY = q.front().first, nowX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i], nextX = nowX + goX[i];

			if (!isinboard(nextY, nextX))
			{
				minDist = min(minDist, visited[nowY][nowX]);
				continue;
			}

			if (board[nextY][nextX] != WALL && !visited[nextY][nextX] && board[nextY][nextX] > visited[nowY][nowX] + 1)
			{
				q.push(make_pair(nextY, nextX));
				visited[nextY][nextX] = visited[nowY][nowX] + 1;
			}
		}

	}	
	

	if (minDist == INF)
		cout << "IMPOSSIBLE";
	else
		cout << minDist;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		fire.clear();
		cin >> M >> N;
		for (int i = 1; i <= N; i++)
		{
			string s;
			cin >> s;
			for (int j = 1; j <= M; j++)
			{
				char c = s[j - 1];
				if (c == '#')
					board[i][j] = WALL;
				else if (c == '@')
					startY = i, startX = j;
				else if (c == '*')
					fire.push_back(make_pair(i, j));
				else
					board[i][j] = INF;
			}
		}
		getboard();
		bfs();
		cout << "\n";
	}
}