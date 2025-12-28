class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());

        long long res = 0;
        int i = happiness.size() - 1;
        for (int j = 0; j < k; j++) {
            if (happiness[i] - j < 0) break;
            res += happiness[i] - j;
            i--;
        }

        return res;
    }
};