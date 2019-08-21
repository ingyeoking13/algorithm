#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> v;
string ans;
int j;

int pi[(int)1e6];

void buildPi(int i)
{
	int begin = 1, matched = 0;
	int len = v[i].length();
	while (begin + matched < len)
	{
		if (v[i][begin + matched] == v[i][matched])
		{
			pi[begin + matched] = matched + 1;
			matched++;
		}
		else
		{
			if (matched == 0) begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}


	for (int i = 0; i < v[0].length(); i++)
	{
		ans += v[0][i];
	}

	j = 0;
	for (int i = 1; i < n; i++)
	{
		int len = ans.length();
		int lenn = v[i].length();
		j = max(len - lenn, 0);

		buildPi(i);

		bool chk = false;

		int begin = j, matched = 0;

		while (begin + matched < len)
		{
			if (matched < lenn && ans[begin + matched] == v[i][matched])
			{
				matched++;
				if (begin + matched == len)
				{
					chk = true;
					break;
				}
			}
			else
			{
				if (matched == 0) begin++;
				else
				{
					begin += matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}

		if (chk)
		{
			for (int k = matched; k < lenn; k++)
			{
				ans += v[i][k];
			}
			j = begin;
		}
		else
		{
			ans += v[i];
			j = ans.length() - lenn;
		}
	}
	cout << ans << "\n";
}