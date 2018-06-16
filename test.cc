#include <iostream>
#include <string>

using namespace std;
int main()
{
	string s;
	cin >> s;

	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == '1'){
			s[i + 1] = !(s[i + 1] - '0') + '0';
		}
	}

	long long n = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		n |= (long long)(s[i] - '0') << (s.length() - i - 1);
	}

	cout << n <<"\n";
}
