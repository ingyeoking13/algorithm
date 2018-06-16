#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
	  vector<int> ans;
		vector<vector<int>> e;
		vector<bool> chk;

		pair<int, int> dfs(int now, vector<int> quiet)
		{
			pair<int, int>ret= {-1, 0x3f3f3f3f};

			chk[now]=1;
			for (int i=0; i<e[now].size(); i++)
			{
				if( chk[e[now][i]] ) continue;

				pair<int, int> next =dfs(e[now][i], quiet);
				if(ret.second> next.second)
				{
					ret = next;
				};
			}
			return ret;
		}

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
			ans.resize(quiet.size());
			e.resize(quiet.size());

			for (int i=0; i<richer.size(); i++)
			{
				int v =richer[i][0], u=richer[i][1];
				e[u].push_back(v);
			}

			for (int i=0; i<richer.size(); i++)
			{
				fill(chk.begin(), chk.end(), 0);
				ans[i] =dfs(i,quiet).first;
			}
			return ans;
    }
};

int main()
{
	vector<vector<int>> ric;
	vector<int> quiet;
	Solution s;
	vector<int> ans;
	ans = s.loudAndRich(ric, quiet);
	for (int i=0; i<ans.size(); i++)
	{
		printf("%d\n", ans[i]);
	}

}
