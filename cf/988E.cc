#include <stdio.h>
#include <set>
#include <string>
#include <queue>
#include <string.h>

using namespace std;
set<string> st;
queue<pair<string, int>> q;

int main()
{
	char s[20];
	scanf("%s",s);
	st.insert(s);
	q.push({s, 0});
	int ans=-1;
	int len = string(s).length();

	int a[10];
	memset(a, 0, sizeof(a));
	for (int i=0; i<len; i++)
	{
		a[s[i]-'0']++;
	}
	if  (
			(a[5] && a[7] ) || 
			(a[2] && a[5]) || 
			(a[0]>=2) || 
			(a[5] && a[0])){
		while(!q.empty())
		{
			pair<string,int> now = q.front();
			q.pop();
			printf("%s\n", now.first.c_str());

			if(now.first[0] == '0') continue;
			if((now.first[len-1] == '5' 
				&& ( now.first[len-2] == '2' || now.first[len-2] == '7'))
					||
					(now.first[len-1]=='0' 
					&& (now.first[len-2]=='5' || now.first[len-2]=='0'))) 
			{
				ans=now.second;
				break;
			}
		
			for (int i=0; i<len-1; i++)
			{
				swap(now.first[i], now.first[i+1]);

				if( st.find(now.first) == st.end()) 
				{
					st.insert(now.first);
					q.push({now.first,now.second+1});
				}

				swap(now.first[i], now.first[i+1]);
			}
			for (int i=len-1; i>0; i--)
			{
				swap(now.first[i], now.first[i-1]);
				if( st.find(now.first) == st.end())
				{
					st.insert(now.first);
					q.push({now.first, now.second+1});
				}
				swap(now.first[i], now.first[i-1]);
			}
		}
	}
	printf("%d\n",ans);
}
