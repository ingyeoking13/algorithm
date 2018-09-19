#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;
int main()
{
  while(1)
	{
		vector<int> ans;
		int prev=-1;
		int n; scanf("%d", &n);
		if (n == 0) break;

		for (int i=0; i<n; i++)
		{
			int tmp; scanf("%d", &tmp);
			if(prev != tmp)
			{
				ans.push_back(tmp);
				prev=tmp;
			}
		}
		
		n = ans.size();
		for (int i=0; i<n; i++)
		{
			printf("%d ", ans[i]);
		}
		printf("$\n");
	}

}
