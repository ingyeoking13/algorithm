#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool mycmp(string& a, string& b)
{
	return a.length() < b.length();
}

int main()
{
	int n; scanf("%d", &n);
	char s[101];
	vector<string> a;
	while(n--)
	{
		scanf("%s", s);
		a.push_back(string(s));
	}
	sort(a.begin(), a.end(), mycmp);

	n = a.size();
	int chk=1;
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if ( a[j].find(a[i]) == -1) chk=0;
		}
	}
	if(chk)
	{
		printf("YES\n");
		for (int i=0; i<n; i++)
		{
			printf("%s\n", a[i].c_str());
		}
	}
	else printf("NO\n");

}
