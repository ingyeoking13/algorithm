#include <iostream>
#include <set>

using namespace std;

int a[(int)2e5];
set<int> cnt;
int ccnt[(int)2e5+1], ans[(int)2e5];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
    int tmp;
    cin >> tmp;
    ccnt[tmp]++;
		cnt.insert(tmp);
	}

	for (int i = 0; i < n; i++)
	{
		int desired = n - a[i];
		if (cnt.find(desired) != cnt.end())
		{
			ans[i] = desired;
      ccnt[desired]--;
      if (ccnt[desired] == 0) cnt.erase(desired);
		}
		else
		{
			auto uit = cnt.upper_bound(desired);
			if (uit == cnt.end()) uit = cnt.upper_bound(0);
			ans[i] = *uit;
      ccnt[*uit]--;
      if (ccnt[*uit] == 0) cnt.erase(*uit);
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << (ans[i] + a[i]) % n << " ";
	}
	cout << "\n";

}
