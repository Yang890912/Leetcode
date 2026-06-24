class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001, 0);
        for (int c : costs) freq[c]++;

        int res = 0;
        for (int c = 1; c < 100001; c++) {
            if (freq[c] == 0) continue;
            
            int buy = min(coins / c, freq[c]);
            res += buy;
            coins -= buy * c;

            if (coins < c) break;
        }

        return res;
    }
};