#include <string.h> 
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool visit[100001];
int INF = 9999;
int tmp;

void ans(int N,int n, vector<vector<int>> directory, int x, int y) {
	
	if (n > N){
		return;
	}
	if (visit[x] == false) {
		for (int i = 0; i < directory.size(); i++) {
			if (directory[i][0] == x) {
				if (directory[i][1] == y) {
					cout << "출력 값:" << n + 1 << endl;
					tmp = min(INF, n+1);
					return;
				}
				else {
					visit[x] = true;
					ans(N,n + 1, directory, directory[i][1], y);
				}
			}
		}

		for (int i = 0; i < directory.size(); i++) {
			if (directory[i][1] == x) {
				visit[x] = true;
				ans(N,n + 1, directory, directory[i][0], y);
			}
		}
	}
}

vector<int> solution(int N, vector<vector<int>> directory, vector<vector<int>> query) {
	vector<int> answer;
	vector<int> start;
	vector<int> stop;
	for (int i = 0; i < query.size(); i++) {
		start.push_back(query[i][0]);
		stop.push_back(query[i][1]);
	}
	for (int k = 0; k < start.size(); k++) {
		//bool visit[100001];
		memset(visit, false, sizeof(visit));
		ans(N,1, directory, start[k], stop[k]);
		answer.push_back(tmp);
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	return answer;
}

int main() {

	vector<vector<int>> directory = { {1, 2},{1, 3},{2, 4},{2, 5} };
	vector<vector<int>> query = { {1, 5},{2, 5},{3, 5},{4, 5} };
	//vector<int> answer;
	 solution(5, directory, query);
	
}