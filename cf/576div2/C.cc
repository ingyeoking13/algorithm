#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a, b, cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, bit;
	cin >> n >> bit;

	bit *= 8;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	sort(a.begin(), a.end());

	cnt.push_back(0);

	b.push_back(a[0]);
	cnt.push_back(1);

	int cur = a[0];
	for (int i = 1; i < n; i++)
	{
		if (cur != a[i])
		{
			cur = a[i];
			b.push_back(cur);
			cnt.push_back(1);
		}
		else cnt[cnt.size() - 1]++;
	}

	for (int i = 1; i < cnt.size(); i++)
	{
		cnt[i] += cnt[i - 1];
	}

  double len = bit/n;
  len =  pow(2, len);

//  cout << len << "\n";

	int ans = 2e9;
	n = cnt.size();

    if ( n <= len )
    {
        cout << 0 << "\n";
        return 0;
    }


	for (int i = 1; i <= n - len; i++)
	{
		int tmp = cnt[n-1] - cnt[ i + len-1 ] + cnt[i-1];
		if (tmp < ans) 
    {
      ans = tmp;
    }
	}
    cout << ans << "\n";
}

