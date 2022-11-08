class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> answer(numRows);
        if (numRows == 1) {
            return s;
        }

        int len = s.size();
        int curRow = 0;
        int dir = 1;
        for (int i=0; i<len; i++) 
        {
            answer[curRow] += s[i];
            curRow += dir;
            if (curRow == numRows || curRow < 0) {
                dir *= -1;
                curRow += (dir * 2);
            }
        }

        string ans;
        for (int i=0; i<numRows; i++) {
            ans += answer[i];
        }
        return ans;
    }
};