class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int m = prices.size();

        long long original = 0;
        for (int i = 0; i < m; i++) original += prices[i] * strategy[i];

        long long kSum = 0;
        for (int i = 0; i < k; i++) kSum += prices[i] * strategy[i];

        vector<long long> nonModify;
        nonModify.push_back(original - kSum);
        for (int i = k; i < m; i++) {
            kSum -= prices[i - k] * strategy[i - k];
            kSum += prices[i] * strategy[i];
            nonModify.push_back(original - kSum);
        }

        long long res = original;
        long long modkSum = 0;
        for (int i = k / 2; i < k; i++) modkSum += prices[i];
        res = max(modkSum + nonModify[0], res);

        for (int i = k, j = 1; i < m, j < nonModify.size(); i++, j++) {
            modkSum -= prices[i - k / 2];
            modkSum += prices[i];
            res = max(modkSum + nonModify[j], res);
        }

        return res;
    }
};