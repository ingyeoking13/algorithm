#include <vector>
#include <stdio.h>
using namespace std;
class Solution {
	public:
	int maxDistToClosest(vector<int>& seats) {
		vector<int> d(seats.size());

		int sz =seats.size();
		int dist=0;
		fill(d.begin(), d.end(), 0x3f3f3f3f);

		int i=0;
		while(!seats[i]) i++;

		for (; i<sz; i++)
		{
			if ( seats[i] ) dist =0;
			d[i]=dist;
			dist++;
		}

		dist=0;
		i=sz-1;
		while(!seats[i]) i--;
		for (; i>=0; i--)
		{
			if ( seats[i] ) dist =0;
			d[i]=min(dist, d[i]);
			dist++;
		}

		int mx =0;
		for (int i=0; i<sz; i++)
		{
			if ( mx < d[i]) mx=d[i];
		}
		return mx;
	}
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	printf("%d\n",s.maxDistToClosest(v));

}
