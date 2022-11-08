class Solution {
public:
    bool go(int i, int j, string& s, string& p, vector<vector<int>>& v) {

        if (i >= s.size()){
            if (j>=p.size()) return 1;
            if (j+1 <p.size() && p[j+1] == '*') {
                return go(i, j+2, s, p, v);
            }
            return 0;
        }

        if (j >= p.size()) {
            return 0;
        }

        if ( v[i][j] != -1 ) {
            return v[i][j];
        }

        // match then
        if ( i < s.size() && (s[i] == p[j] || p[j] == '.' )) {
            if ( j+1 < p.size() && p[j+1] == '*' ) {
                v[i][j] = go(i+1, j+2, s, p, v) || go(i+1, j, s, p, v) || go(i, j+2, s, p, v);
                return v[i][j];
            } else {
                v[i][j] = go(i+1, j+1, s, p, v);
                return v[i][j];
            }
        }
        // un-match but star can be (0~n) or j can
        if ( j+1 < p.size() && p[j+1] == '*' ) {
            int result = go(i, j+2, s, p, v);
            if ( i < s.size() ) {
                return v[i][j] = result;
            }
            return result;
        }

        // un-match
        return v[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        int imax = s.size(), jmax = p.size();
        vector<vector<int>> v(imax, vector<int>(jmax,-1));
        return go(0, 0, s, p, v);
    }
};