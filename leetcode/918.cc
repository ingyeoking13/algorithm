class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) 
    {

        vector<long long> dp_max(A.size());
        vector<long long> dp_min(A.size());
        dp_max[0] = dp_min[0] = A[0];
        for (int i=1; i<A.size(); i++)
        {
            if (A[i] < dp_max[i-1] +A[i] ) dp_max[i] = dp_max[i-1] + A[i];
            if (A[i] > dp_min[i-1] +A[i]) dp_min[i] = dp_min[i-1] + A[i];
        }

        long long sum =0;
        for (int i=0; i<A.size(); i++) sum+=A[i];
        return  max(sum,)
    }
};