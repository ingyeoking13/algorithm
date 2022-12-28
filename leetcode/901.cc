class StockSpanner {
public:
    stack<pair<int, int>> v;
    StockSpanner() {
    }
    
    int next(int price) {
        int ans = 1;

        while (!v.empty() && v.top().first <= price ) {
            ans += v.top().second;
            v.pop();
        }
        v.push({price, ans});
        return ans;
    }
};