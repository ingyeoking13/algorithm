#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	int n; scanf("%d", &n);

	string str;
	for (int i = 0; i<n; i++)
	{
		int tmp; scanf("%d", &tmp);
		str += tmp + '0';
	}


	vector<string> vs;
	vector<int> ans;
	int m; scanf("%d", &m);
	vs.resize(m);

	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			int tmp; scanf("%d", &tmp);
			vs[i] += tmp + '0';
		}
		string tmp = vs[i];
		vs[i].append(tmp.begin(), tmp.end());
		if (vs[i].find(str) != -1)  ans.push_back(i);
		else
		{
			string tmp2;
			for (int j = 0; j < n; j++)
			{
				if (vs[i][j] == '1') tmp2 += '3';
				else if (vs[i][j] == '2') tmp2 += '4';
				else if (vs[i][j] == '3') tmp2 += '1';
				else tmp2 += '2';
			}
			reverse(tmp2.begin(), tmp2.end());
			tmp = tmp2;
			tmp2.append(tmp.begin(), tmp.end());
			if (tmp2.find(str) != -1) ans.push_back(i);
		}
	}
	printf("%lu\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{

		for (int j = 0; j < str.size(); j++)
		{
			printf("%d ", vs[ans[i]][j]-'0');
		}
		printf("\n");
	}
}
