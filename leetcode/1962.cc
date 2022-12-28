class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int i : piles) {
            pq.push(i);
        }
        while(k--) {
            int v = pq.top();
            pq.pop();
            pq.push(v - v/2);
        }

        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};