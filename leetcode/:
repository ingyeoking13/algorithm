class Solution {
public:
	int numFriendRequests(vector<int>& a) {

		int ans=0;
		for (int i =0; i< a.size(); i++){
			for (int j=i+1; j<a.size(); j++){
				int chk=0;
				if ( a[j] <= 0.5* (double)a[i] + 7 ) chk=1;
				if ( a[j] > a[i] ) chk=1;
				if ( a[j] > 100 && a[i] < 100 ) chk=1;
				if(!chk) ans++;

				if ( a[i] <= 0.5* (double)a[j] + 7 ) continue;
				if ( a[i] > a[j] ) continue;
				if ( a[i] > 100 && a[j] < 100 ) continue;
				ans++;
			}
		}

		return ans;
			
	}
};
