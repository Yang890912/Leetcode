class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        for (int num : nums) {
            freq[num]++;
        }

        sort(freq.rbegin(), freq.rend());
        int res = freq[0];
        for (int i = 1; i < freq.size(); i++) {
            if (freq[i] != freq[i - 1]) break;
            res += freq[i];
        }

        return res;
    }
};