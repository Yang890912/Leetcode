class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int total = numSet.size();
        int res = 0;
        
        int left = 0, right = 0;
        int count = 0;
        vector<int> freq(2001, 0);

        while (left < nums.size() && right < nums.size()) {
            if (freq[nums[right]] == 0) count++;
            
            freq[nums[right]]++;

            while (count >= total) {
                res += (nums.size() - right);
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) count--;
                left++;
            }
            right++;
        }

        return res;
    }
};