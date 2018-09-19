#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int n, k; scanf("%d %d", &n, &k);
	vector<int> ans, chk;
	chk.resize(101);
	fill(chk.begin(), chk.end(), 0);

	for(int i=1; i<=n; i++)
	{
		int tmp; scanf("%d", &tmp);

		if(chk[tmp]==0)
		{
			ans.push_back(i);
			chk[tmp]=1;
		}
	}

	if ( ans.size() >= k)
	{
		printf("YES\n");
		for (int i=0; i<k; i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else printf("NO\n");

}
