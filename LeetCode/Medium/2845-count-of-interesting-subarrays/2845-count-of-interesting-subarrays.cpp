class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long res = 0;
        int prefix = 0;
        unordered_map<int, long long> um;
        um[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % modulo == k) prefix++;

            res += um[(prefix + modulo - k) % modulo];
            um[prefix % modulo]++;
        }

        return res;
    }
};