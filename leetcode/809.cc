class Solution {
public:
	int expressiveWords(string S, vector<string>& words) {
		int n = S.length(), ans=0;

		for (int i=0; i<words.size(); i++){

			int ans =0, k=0, chk=1; 

			for (int j=0; j<n; j++ ){
				int cnt=1, st=S[j];
				while ( j<n &&  S[j+1] == st) cnt++, j++;

				if  (cnt >=3 ){
					int len = cnt/3;

					int tmpcnt=0;
					while ( k<words[i].length() && words[i][k] == st) tmpcnt++, k++;

					if ( tmpcnt < len) { chk=0; break;}
				}
				else {
					for (int l = 0; l<cnt; l++) {
						if ( k == words[i].length() ) {chk=0; break; }
						if ( words[i][k] ==st) k++;
						else { chk=0; break; }
					}
				}
			}

			if ( chk ) ans++;
		}
		return ans;
	}

};
