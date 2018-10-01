#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> s;
vector<vector<vector<int>>> status;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };

char comb_dir[4][4] = {
	'F', 'R', 'L', 'B',
	'R', 'B', 'F', 'L',
	'L', 'F', 'B', 'R',
	'B', 'L', 'R', 'F'
};

bool myChkfunc(pair<int, int> now, int dir)
{
	for (auto i : status[now.first][now.second]) {
		if (i == dir) return false;
	}
	return true;
}

int ret_dir(char c)
{
	if (c == 'F') return 0;
	if (c == 'R') return 1;
	if (c == 'L') return 2;
	return 3;
}

int main() {
	int n;
	cin >> n;
	s.resize(n, vector<string>(n));
	status.resize(n, vector<vector<int>>(n));

	/*
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			for (auto i : status[x][y]) cout << i << "  ";
			// @todo Write your code here.
		}
		cout << endl;
	}
	*/

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			cin >> s[x][y];
			// @todo Write your code here.
		}
	}
	// @todo Write your code here.

	pair<int, int> now = { 0, 0 };
	int bef = -1;
	bool chk = 0;
	while (1)
	{
		cout << now.first << " " << now.second << endl;
		string tmp = s[now.first][now.second];
		if (bef < 0)
		{
			bef = 3;
			status[now.first][now.second].push_back(bef);
			int tt =  stoi(tmp.substr(1));
			now.first += tt;
		}
		else
		{
			bef = ret_dir(comb_dir[bef][ret_dir(tmp[0])]);
			if (!myChkfunc(now, bef)) break;
			status[now.first][now.second].push_back(bef);
			now.first += stoi(tmp.substr(1))*dx[bef];
			now.second += stoi(tmp.substr(1))*dy[bef];
		}
	}

	cout << now.second << " " << now.first << endl;
	return 0;
}