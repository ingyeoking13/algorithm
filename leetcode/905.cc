class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> odd, even;
        for (auto i: A)
        {
            if (i%2 == 1 ) odd.push_back(i);
            else even.push_back(i);
        }
        for (auto i : odd)
        {
            even.push_back(i);
        }
        return even;
    }
};