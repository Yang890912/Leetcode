class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 2));
        int res = 0;

        for (int i = 2; i < arr.size(); i++) {
            int left = 0;
            int right = i - 1;

            while (left < right) {
                if (arr[left] + arr[right] < arr[i]) left++;
                else if (arr[left] + arr[right] > arr[i]) right--;
                else {
                    dp[right][i] = dp[left][right] + 1;
                    res = max(dp[right][i], res);
                    left++;
                    right--;
                }
            }
        }

        return res;
    }
};