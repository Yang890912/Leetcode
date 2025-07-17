class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = prices[0];
        int currMax = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (left > prices[i]) left = prices[i];
            else if (prices[i] - left > currMax) currMax = prices[i] - left;
        }
        
        return currMax;
    }
};