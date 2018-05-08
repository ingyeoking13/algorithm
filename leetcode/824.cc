class Solution {
public:
  struct myword{
    string s;
    myword(string s) : s(s) {}
  };

  bool vow(char a){
    if ( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a== 'u' ) return 1;
    return 0;
  }

  string toGoatLatin(string S) {
    vector<myword> vw;
    string tmp;
    for (int i=0; i<S.length(); i++){
      if ( S[i] == ' ' ){
        vw.push_back(tmp);
        tmp.clear();
      }
      else tmp+= S[i];
    }
		vw.push_back(tmp);

    for (int i=0; i< vw.size(); i++){
      if ( vow(vw[i].s[0]) ){
        vw[i].s += "m";
				vw[i].s += "a";
        for (int j=0; j<=i; j++)  vw[i].s+= "a";
      }
      else {
        char tmp = vw[i].s[0];
        vw[i].s.erase(0, 1);
        vw[i].s+= tmp;
        vw[i].s += "ma";
        for (int j=0; j<=i; j++) vw[i].s += "a";
      }
    }
    string ans;

    for (int i=0; i<vw.size(); i++) {
			if ( i <vw.size() -1){
				ans += vw[i].s;
				ans += " ";
			}
			else ans+= vw[i].s;
    }
		return ans;
  }

};

