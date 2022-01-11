class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minIdx = 0;
        for (int i = 0; i < prices.size(); i++) {
            ans = max(ans, prices[i]-prices[minIdx]);
            if (prices[i] < prices[minIdx]) {
                minIdx = i;
            }
        }
        return ans;
    }
};