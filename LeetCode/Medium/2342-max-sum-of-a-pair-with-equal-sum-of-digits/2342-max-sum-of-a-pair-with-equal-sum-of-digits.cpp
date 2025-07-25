class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> digitSumMap;
        for (int n : nums) {
            int _n = n;
            int digitSum = 0;
            while (_n >= 10) {
                digitSum += (_n % 10);
                _n /= 10;
            }
            digitSum += _n;
            digitSumMap[digitSum].push_back(n);
        }

        int maxSum = -1;
        for (auto& entry : digitSumMap) {
            vector<int>& numsWithSameDigitSum = entry.second;
            if (numsWithSameDigitSum.size() >= 2) {
               sort(numsWithSameDigitSum.rbegin(), numsWithSameDigitSum.rend());
               int currMax = numsWithSameDigitSum[0] + numsWithSameDigitSum[1];
               maxSum = currMax > maxSum ? currMax : maxSum;
            }
        }
        
        return maxSum;
    }
};