class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minNum = LLONG_MAX;
        long long maxNum = LLONG_MIN;
        long long prefixSum = 0;

        for (int i = 0; i < differences.size(); i++) {
            prefixSum += differences[i];
            minNum = min(minNum, prefixSum);
            maxNum = max(maxNum, prefixSum);
        }

        int res = 0;
        long long start = max(lower - minNum, (long long)lower);
        long long end = min(upper - maxNum, (long long)upper);

        if (end - start >= 0) res = end - start + 1;

        return res;

    }
};