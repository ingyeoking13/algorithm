#include <bits/stdc++.h>

using namespace std;
class InterestingParty{
    public:
    int bestInvitation( vector <string> first, vector <string> second){
        int ans=0, n = first.size();
        for (int i=0; i<n; i++){
            int cnt1=1, cnt2=1;
            for (int j=0; j<n; j++){
                if (i!=j){
                    if (first[i] == first[j] ) cnt1++;
                    if (first[i] == second[j] ) cnt1++;
                    if (second[i] == first[j] ) cnt2++;
                    if (second[i] == second[j] ) cnt2++;
                }
            }
            if (ans < cnt1) ans= cnt1;
            if (ans < cnt2) ans= cnt2;
        }
    	return ans;
    }
}
