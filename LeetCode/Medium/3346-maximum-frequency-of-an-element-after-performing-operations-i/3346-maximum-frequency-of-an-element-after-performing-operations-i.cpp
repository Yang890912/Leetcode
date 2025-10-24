class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> mapping;
        for (int num : nums) mapping[num]++;

        int res = 0;
        int freq = 0;
        int lower = mapping.begin()->first;
        int upper = prev(mapping.end())->first;
        auto i = mapping.begin(), j = mapping.begin();
        for (int target = lower; target <= upper; target++) {
            while (j != mapping.end() && j->first <= target + k) {
                freq += j->second;
                j++;
            }
            while (i != mapping.end() && i->first < target - k) {
                freq -= i->second;
                i++;
            }

            res = max(res, min(numOperations + mapping[target], freq));
        }

        return res;
    }
};